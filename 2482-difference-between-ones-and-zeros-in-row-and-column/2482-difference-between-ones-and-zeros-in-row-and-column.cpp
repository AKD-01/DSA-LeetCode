class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& g) {
        int si = g.size(), sj = g[0].size();
    vector<int> r(g.size()), c(g[0].size());
    for (int i = 0; i < r.size(); ++i)
        for (int j = 0; j < c.size(); ++j) {
            r[i] += g[i][j];
            c[j] += g[i][j];
        }
    for (int i = 0; i < si; ++i)
        for (int j = 0; j < sj; ++j)
            g[i][j] = r[i] + c[j] - (si - r[i]) - (sj - c[j]);
    return g;
    }
};