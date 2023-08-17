class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visit(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q; 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    visit[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            
            int s = q.size();
            
            for(int i=0;i<s;i++){
                
                auto p = q.front();
                q.pop();
                
                int x = p.first;
                int y = p.second;
                
                if(x+1<n && visit[x+1][y]>visit[x][y]+1){
                    q.push({x+1,y});
                    visit[x+1][y] = visit[x][y]+1;
                }
                
                if(y+1<m && visit[x][y+1]>visit[x][y]+1){
                    q.push({x,y+1});
                    visit[x][y+1] = visit[x][y]+1;
                }
                
                if(x-1>=0 && visit[x-1][y]>visit[x][y]+1){
                    q.push({x-1,y});
                    visit[x-1][y] = visit[x][y]+1;
                }
                
                if(y-1>=0 && visit[x][y-1]>visit[x][y]+1){
                    q.push({x,y-1});
                    visit[x][y-1] = visit[x][y]+1;
                }
                
            }
            
        }
        
        return visit;
    }
};