class Solution {
public:
    long long dp[101][101] = {};
long long dfs(int i, int j, vector<vector<int>>& f, vector<int>& r) {
    if (j >= r.size())
        return 0;
    if (i >= f.size())
        return 200000000000L;
    if (dp[i][j] == 0) {
        dp[i][j] = 1 + dfs(i + 1, j, f, r);
        long long dist = 0;
        for (int n = 0; j + n < r.size() && n < f[i][1]; ++n) {
            dist += abs(f[i][0] - r[j + n]);
            dp[i][j] = min(dp[i][j], 1 + dist + dfs(i + 1, j + n + 1, f, r));
        }
    }
    return dp[i][j] - 1;
}
long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
    sort(begin(r), end(r));
    sort(begin(f), end(f));
    return dfs(0, 0, f, r);
}
};