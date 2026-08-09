class Solution {
public:
    int dfs(int ind, int m, vector<int>& piles, int n, vector<vector<int>>& dp) {
        if (ind >= n) return 0;
        if (dp[ind][m] != -1) return dp[ind][m];
        int tot = 0, ans = INT_MIN;
        for (int x = 0; x < 2 * m; x++) {
            if (ind + x < n) tot += piles[ind + x];
            ans = max(ans, tot - dfs(ind + x + 1, max(m, x + 1), piles, n, dp));
        }

        return dp[ind][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size(), sum = 0;
        for (auto &it : piles) sum += it;

        vector<vector<int>> dp(n, vector<int>(2 * n, -1));
        int aliceBob = dfs(0, 1, piles, n, dp);
        return (sum + aliceBob) / 2;
    }
};