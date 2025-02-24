class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amt) {
        n = amt.size();
        tree.resize(n);
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        distBob.resize(n);
        return dfs(0, -1, 0, bob, amt);
    }

private:
    vector<vector<int>> tree;
    vector<int> distBob;
    int n;

    int dfs(int node, int parent, int time, int bob, vector<int>& amt) {
        int maxChild = INT_MIN, income = 0;

        if (node == bob) distBob[node] = 0;
        else distBob[node] = n;

        for (int adj : tree[node]) {
            if (adj != parent) {
                maxChild = max(maxChild, dfs(adj, node, time + 1, bob, amt));
                distBob[node] = min(distBob[node], distBob[adj] + 1);
            }
        }

        if (distBob[node] > time) income += amt[node];
        else if (distBob[node] == time) income += amt[node] / 2;

        return maxChild == INT_MIN ? income : income + maxChild;
    }
};
