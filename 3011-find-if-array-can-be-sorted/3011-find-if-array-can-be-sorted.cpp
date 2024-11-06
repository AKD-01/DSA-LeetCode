class Solution {
public:
    bool canSortArray(vector<int>& nums) {
       vector<int> count;
        int n=nums.size();
        for(auto it:nums){
            int tmp=0;
            while(it>0){
                if(it&1) tmp++;
                it=(it>>1);
            }
            count.push_back(tmp);
        }
        
        int prev_max=-1e5;
        for(int i=0;i<n;){
            int start=i;
            int end=i;
            int curr_max=-1e5,curr_min=1e5;
            for(int j=i;j<n;j++){
                if(count[j]==count[i]){
                    curr_max=max(curr_max,nums[j]);
                    curr_min=min(curr_min,nums[j]);
                    end++;
                }else break;
            }
            i=end;
            if(curr_min<prev_max) return false;
            prev_max=curr_max;
        }
        return true;  
    }
};