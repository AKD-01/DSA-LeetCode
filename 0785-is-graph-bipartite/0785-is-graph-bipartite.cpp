//Using DFS
class Solution {
private:
    bool dfs(int node, int col, vector<vector<int>>& graph, int color[]) {
        color[node]=col;
        for(auto it: graph[node]) {
            if(color[it]==-1) {
                if(dfs(it, !col, graph, color)==false) return false;
            }
            else if(color[it]==col) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int color[n];
        for(int i=0; i<n; i++) {
            color[i]=-1;
        }
        for(int i=0; i<n; i++) {
            if(color[i]==-1) {
                if(dfs(i, 0, graph, color) == false) return false;
            }
        }
        return true;
    }
};
//Using BFS
/*
class Solution {
private:
    bool check(int start, vector<vector<int>>& graph, int color[]) {
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : graph[node]) {
                if(color[it]==-1) {
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        for(int i=0; i<n; i++) {
            color[i]=-1;
        }
        for(int i=0; i<n; i++) {
            if(color[i]==-1) {
                if(check(i, graph, color) == false) return false;
            }
        }
        return true;
    }
};
*/