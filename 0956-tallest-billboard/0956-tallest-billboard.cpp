class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
         unordered_map<int, int> dp;
        dp[0] = 0;
        for (int x : rods) {
            unordered_map<int, int> cur(dp);
            for (auto it: cur) {
                int d = it.first;
                dp[d + x] = max(dp[d + x],cur[d]);
                dp[abs(d - x)] = max(dp[abs(d - x)], cur[d] + min(d, x));
            }
        }
        return dp[0];
    }
};