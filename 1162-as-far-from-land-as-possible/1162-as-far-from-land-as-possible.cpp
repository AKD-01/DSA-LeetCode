class Solution {
    const int dirs[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        
        queue<pair<int,int>> q;
        
        //It's a Simple Reverse BFS Approach
        //Insert indexes of all the 1s
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(grid[i][j])
                    q.emplace(i,j),
                    dist[i][j]=0;
        
        int ans=-1;
        
        auto isValid=[&](int r,int c){
            return r>=0 && r<n & c>=0 && c<m;
        };
        
        
        
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            
            //Traverse all 4 directions
            for(int k=0; k<4; ++k){
                int nr=r+dirs[k][0];
                int nc=c+dirs[k][1];
                
                //If we jump onto a 0 and it's not visited, update it's distance to current visited + 1
				//Unvisited 0s are marked -1 in distance vector.......
                if(isValid(nr, nc) && !grid[nr][nc] && dist[nr][nc]==-1){
                    dist[nr][nc]=dist[r][c]+1;
                    q.emplace(nr, nc);
                    ans=max(ans, dist[nr][nc]);  //Ans will be max value of all the distances we need to cover from a zero to it's nearest one
                }
            }
        }
        return ans;  // :)
    }
};