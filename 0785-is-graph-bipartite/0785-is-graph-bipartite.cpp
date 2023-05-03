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