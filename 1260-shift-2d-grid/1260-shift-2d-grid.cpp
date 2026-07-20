class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        int total = m*n;
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cur = i*n + j;
                cur = cur + k;
                cur = cur%total;
                int newI = cur/n;
                int newJ = cur%n;
                ans[newI][newJ]=grid[i][j];
            }
        }
    return ans;
    }
};