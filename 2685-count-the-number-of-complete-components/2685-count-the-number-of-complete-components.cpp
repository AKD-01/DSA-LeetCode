class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                queue<int> q;
                q.push(i);
                vis[i] = true;

                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    comp.push_back(cur);

                    for (int nei : adj[cur]) {
                        if (!vis[nei]) {
                            q.push(nei);
                            vis[nei] = true;
                        }
                    }
                }

                bool complete = true;
                for (int node : comp) {
                    if (adj[node].size() != comp.size() - 1) {
                        complete = false;
                        break;
                    }
                }

                if (complete) count++;
            }
        }

        return count;
    }
};
