class Solution {
    void dfs(vector<vector<int>> &grid2, int i , int j){
        if(i <0 || i>=grid2.size() || j <0 || j >=grid2[i].size()){
            return;
        }
        if(grid2[i][j]!=0){
            return;
        }
        grid2[i][j] = 1;
        dfs(grid2,i-1,j);
        dfs(grid2,i+1,j);
        dfs(grid2,i,j-1);
        dfs(grid2,i,j+1);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<int>>grid2(grid.size()*3,vector<int>(grid.size()*3,0));
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j]=='/'){
                   grid2[i*3+0][j*3+2] = 1;
                   grid2[i*3+1][j*3+1] = 1;
                   grid2[i*3+2][j*3+0] = 1;
                  }else if(grid[i][j]=='\\'){
                   grid2[i*3+0][j*3+0] = 1;
                   grid2[i*3+1][j*3+1] = 1;
                   grid2[i*3+2][j*3+2] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<grid2.size();i++){
            for(int j = 0;j<grid2[i].size();j++){
                if(grid2[i][j]==0){
                    dfs(grid2,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};  