class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
    vector<int> dp(n, 0);

   for (int i = 0; i < n; i++) {
        dp[i] = nums[i];
    }

   for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
 dp[i] = max(nums[i] - dp[i + 1], nums[j] - dp[i]);
        }
    }

    return dp[0] >= 0;
    }
};