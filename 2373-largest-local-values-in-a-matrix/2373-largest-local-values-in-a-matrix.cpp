class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n - 2; ++i)
            for (int j = 0; j < n - 2; ++j)
                for (int ii = i; ii < i + 3; ++ii)
                    for (int jj = j; jj < j + 3; ++jj)
                        res[i][j] = max(res[i][j], g[ii][jj]);
        return res;
    }
};