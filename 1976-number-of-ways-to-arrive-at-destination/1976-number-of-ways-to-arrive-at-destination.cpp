#define ll long long
const int MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ll dp[n][n][2];

        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                dp[i][j][0] = (i == j) ? 0 : 1e12;
                dp[i][j][1] = (i == j) ? 1 : 0;
            }
        }

        for (auto& r : roads) {
            ll u = r[0], v = r[1], t = r[2];
            dp[u][v][0] = dp[v][u][0] = t;
            dp[u][v][1] = dp[v][u][1] = 1;
        }

        for (ll k = 0; k < n; k++) {
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < n; j++) {
                    if (i != k && j != k) {
                        ll newT = dp[i][k][0] + dp[k][j][0];

                        if (newT < dp[i][j][0]) {
                            dp[i][j][0] = newT;
                            dp[i][j][1] = (dp[i][k][1] * dp[k][j][1]) % MOD;
                        } else if (newT == dp[i][j][0]) {
                            dp[i][j][1] = (dp[i][j][1] + dp[i][k][1] * dp[k][j][1]) % MOD;
                        }
                    }
                }
            }
        }

        return dp[n - 1][0][1];
    }
};
