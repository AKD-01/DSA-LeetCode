class Solution {
public:
    int bfs(vector<vector<int>>&grid)
    {
        int num_islands=0;
        int m=grid.size();
        int n=grid[0].size();
        unordered_set<int>set;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0 || set.find(i*n+j)!=set.end())
                    continue;
                num_islands++;
                if(num_islands>1)
                    return 2;
                queue<int>q;
                q.push(i*n+j);
                set.insert(i*n+j);
                while(!q.empty())
                {
                    int temp=q.front();
                    q.pop();
                    int x=temp/n;
                    int y=temp%n;
                    if(x<m-1 && grid[x+1][y]==1 && set.find((x+1)*n+y)==set.end())
                    {
                        set.insert((x+1)*n+y);
                        q.push((x+1)*n+y);
                    }
                    if(x>0 && grid[x-1][y]==1 && set.find((x-1)*n+y)==set.end())
                    {
                        set.insert((x-1)*n+y);
                        q.push((x-1)*n+y);
                    }
                    if(y<n-1 && grid[x][y+1]==1 && set.find(x*n+y+1)==set.end())
                    {
                        set.insert(x*n+y+1);
                        q.push(x*n+y+1);
                    }
                    if(y>0 && grid[x][y-1]==1 && set.find(x*n+y-1)==set.end())
                    {
                        set.insert(x*n+y-1);
                        q.push(x*n+y-1);
                    }
                }
            }
        }
        return num_islands;
    }
    int minDays(vector<vector<int>>& grid) 
    {
        if(bfs(grid)!=1)
            return 0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                    continue;
                grid[i][j]=0;
                if(bfs(grid)!=1)
                    return 1;
                grid[i][j]=1;
            }
        }
        return 2;
        
    }
};
