class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        if (m < 3 || n < 3) return 0;
        for (int i = 0; i < m - 2; i++)
            for (int j = 0; j < n - 2; j++)
                res += isMagicSquare(i, j, grid);
        return res;
    }
private:
    bool isMagicSquare(int r, int c, vector<vector<int>>& grid){
        int rows[3] = {}, cols[3] = {}, diag[2] = {};
        bool s[10] = {};
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                int val = grid[r + i][c + j];
                if (val < 1 || val > 9 || s[val])
                    return false;
                s[val] = true;
                rows[i] += val;
                cols[j] += val;
                if (i == j)
                    diag[0] += val;
                if (i + j == 2)
                    diag[1] += val;
            }
        }
        return (rows[0] == rows[1] && rows[1] == rows[2]) && 
               (cols[0] == cols[1] && cols[1] == cols[2]) && 
               (diag[0] == diag[1]);
    }
};