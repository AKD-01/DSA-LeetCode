class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int nlayer = min(m / 2, n / 2);  
        for (int layer = 0; layer < nlayer; ++layer) {
            vector<int> r, c, val; 
            for (int i = layer; i < m - layer - 1; ++i) {  // left
                r.push_back(i);
                c.push_back(layer);
                val.push_back(grid[i][layer]);
            }
            for (int j = layer; j < n - layer - 1; ++j) {  // down
                r.push_back(m - layer - 1);
                c.push_back(j);
                val.push_back(grid[m - layer - 1][j]);
            }
            for (int i = m - layer - 1; i > layer; --i) {  // right
                r.push_back(i);
                c.push_back(n - layer - 1);
                val.push_back(grid[i][n - layer - 1]);
            }
            for (int j = n - layer - 1; j > layer; --j) {  // up
                r.push_back(layer);
                c.push_back(j);
                val.push_back(grid[layer][j]);
            }
            int total = val.size();  
            int kk = k % total;     
            for (int i = 0; i < total; ++i) {
                int idx =
                    (i + total - kk) % total;  
                grid[r[i]][c[i]] = val[idx];
            }
        }
        return grid;
    }
};