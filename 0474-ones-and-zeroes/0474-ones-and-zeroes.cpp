class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        map<pair<int, int>, int> dp;
        dp[{0, 0}] = 0;

        for (auto &s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c == '0') zeros++;
                else ones++;
            }

            map<pair<int, int>, int> newdp;

            for (auto &[state, val] : dp) {
                int used0 = state.first + zeros;
                int used1 = state.second + ones;

                if (used0 <= m && used1 <= n) {
                    if (!dp.count({used0, used1}) || dp[{used0, used1}] < val + 1) {
                        newdp[{used0, used1}] = val + 1;
                    }
                }
            }

            for (auto &[state, val] : newdp) {
                dp[state] = max(dp[state], val);
            }
        }

        int ans = 0;
        for (auto &[_, val] : dp) ans = max(ans, val);
        return ans;
    }
};