class Solution {
public:
    int dp[2501];
    int lis(int i,vector<int>& nums){
        if(dp[i]!=-1) return dp[i];
        int ians=1;
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                ians=max(ians,lis(j,nums)+1);
            }
        }
        return dp[i]=ians;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            dp[i]=-1;
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            ans=max(ans,lis(i,nums));
        }
        return ans;
    }
};