class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        vector<bool> visited(n, false);
        vector<int> comp(n), compCost;
        int compId = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                compCost.push_back(dfs(i, graph, visited, comp, compId));
                compId++;
            }
        }

        vector<int> res;
        for (auto& q : queries) {
            res.push_back(comp[q[0]] == comp[q[1]] ? compCost[comp[q[0]]] : -1);
        }

        return res;
    }

private:
    int dfs(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& visited, vector<int>& comp, int compId) {
        int cost = INT_MAX;
        visited[node] = true;
        comp[node] = compId;

        for (auto& [next, weight] : graph[node]) {
            cost &= weight;
            if (!visited[next]) {
                cost &= dfs(next, graph, visited, comp, compId);
            }
        }

        return cost;
    }
};
