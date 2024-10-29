class Solution {
    int dfs(int n, int m, vector<vector<int>>& grid, int i, int j, int prev) {
        if(i < 0 or j < 0 or i >= n or j >= m or grid[i][j] <= prev)return 0;
        
        int val = grid[i][j];
        grid[i][j] = 0;
        
        int ans = max({dfs(n,m,grid,i-1,j+1,val), dfs(n,m,grid,i,j+1,val),dfs(n,m,grid,i+1,j+1,val)}) + 1;
        
        return ans;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = size(grid), m = size(grid[0]), res = 0;
        
        for(int i = 0; i < n; i++) {
            res = max(res,dfs(n,m,grid,i,0,-1e6));
        }
        
        return res - 1;
    }
};