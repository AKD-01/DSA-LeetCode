class Solution {
    int m,n;
public:
    int dfs(vector<vector<int>> &grid,int i,int j){
        if(grid[i][j]==0) return 0;
        int result=0;
        int temp=grid[i][j];
        grid[i][j]=0;
        if(i>0) result=max(result,temp+dfs(grid,i-1,j));
        if(j>0) result=max(result,temp+dfs(grid,i,j-1));
        if(i<m-1) result=max(result,temp+dfs(grid,i+1,j));
        if(j<n-1) result=max(result,temp+dfs(grid,i,j+1));
        grid[i][j]=temp;
        return result;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int result=0;
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                result=max(result,dfs(grid,i,j));   
        return result;
    }
};