int dp[201][20001];

class Solution {
public:
    int func(int ind,int sum,vector<int>& nums){
        if(sum == 0) return true;
        if(ind < 0) return false;
        if(dp[ind][sum] != -1) return dp[ind][sum]; 

        bool isPossible = func(ind-1,sum,nums);
        if(sum-nums[ind] >= 0)
        isPossible = isPossible | func(ind-1,sum-nums[ind],nums);

        return dp[ind][sum] = isPossible;
    }

    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 != 0) return false; sum = sum / 2;
        return func(nums.size()-1,sum,nums); 
    }
};