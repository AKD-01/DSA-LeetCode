class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> visited(n);
        vector<vector<int>> adj(n), back(n);
        queue<int> q;
        q.push(0);
        int ans = 0;
        for (auto c : connections){
            adj[c[0]].push_back(c[1]);
            back[c[1]].push_back(c[0]);
        }
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            visited[curr] = 1;
            // change dir for all arrows facing out
            for (auto a: adj[curr]){
                if (!visited[a]){
                    ans++;
                    q.push(a);
                }
            }
            // push other nodes so we visit everything
            for (auto b: back[curr]){
                if (!visited[b]) q.push(b);
            }
        }
        return ans;
    }
};