class Solution {
public:
    void dfs(int src,vector<int>g[],vector<bool>&vis){
        vis[src] = true;
        for(auto &child: g[src]){
            if(!vis[child]){
                vis[child] = true;
                dfs(child,g,vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int x = edges.size();
        vector<bool> vis(n,false);
        vector<int> g[n];
        for(int i=0; i<x; ++i){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0; i<n; ++i){
            if(!vis[i]){
                dfs(i,g,vis);
                if((vis[source] && !vis[destination]) || (!vis[source] && vis[destination])){
                    return false;
                }
            }
        } 
        return true;
    }
};