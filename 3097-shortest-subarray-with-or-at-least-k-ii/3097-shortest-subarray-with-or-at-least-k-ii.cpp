class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int>one(32,0);
        int i=0;
        int ans=1e9;
        for(int j=0;j<nums.size();j++)
        {
            for(int k=0;k<32;k++)
            {
                if(nums[j]&(1<<k))one[k]++;
            }
            long num=0;
            for(int k=0;k<32;k++)if(one[k])num+=(long)pow(2,k);
            
            while(num>=k&&i<=j)
            {
                ans=min(ans,j-i+1);
                for(int k=0;k<32;k++)
                 {
                    if(nums[i]&(1<<k))one[k]--; 
                 }
                long long newNum=0;
                for(int k=0;k<32;k++)if(one[k])newNum+=(long)pow(2,k);
                
                num=newNum;
                i++;
            }
        }
        return ans==1e9?-1:ans;
    }
};