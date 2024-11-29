class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int row=grid.size(), col=grid[0].size(), ans=INT_MAX;
        vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    
        visited[0][0]=true;
        
        pq.push({0, 0, 0});
        if(grid[1][0]<=1){
            pq.push({1, 1, 0});
            visited[1][0]=true;
        }
        if(grid[0][1]<=1){
            pq.push({1, 0, 1});
            visited[0][1]=true;
        }
        
        if(pq.size()==1){
            return -1;
        }
        
        while(pq.size()){
            auto curr = pq.top();
            pq.pop();
            int time=curr[0];
            int r=curr[1], c=curr[2];
            
            if(r==row-1 && c==col-1){
                ans=min(ans, time);
            }
            
            for(auto& i:direction){
                int newR=r+i[0];
                int newC=c+i[1];
                if(newR>=0 && newR<row && newC>=0 && newC<col && visited[newR][newC]==false){
                    if(time+1>=grid[newR][newC]){
                        pq.push({time+1, newR, newC});
                    }else{
                        int diff=grid[newR][newC]-time;
                        if(diff%2==0){
                            pq.push({grid[newR][newC]+1, newR, newC});
                        }else{
                            pq.push({grid[newR][newC], newR, newC});
                        }
                    }
                    visited[newR][newC]=true;
                }
            }
        }
        return ans;
    }
};