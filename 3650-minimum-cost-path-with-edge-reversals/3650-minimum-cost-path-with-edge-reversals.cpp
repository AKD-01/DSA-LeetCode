class Solution {
    using PII = pair<int, int>;

public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<PII>> g(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1], w = e[2];
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, 2 * w);
        }

        vector<int> d(n, INT_MAX);
        vector<bool> v(n, false);
        priority_queue<PII, vector<PII>, greater<PII>> q;
        d[0] = 0;
        q.emplace(0, 0);

        while (!q.empty()) {
            int x = q.top().second;
            q.pop();
            if (x == n - 1) {
                return d[x];
            }
            if (v[x]) {
                continue;
            }
            v[x] = 1;

            for (auto& [y, w] : g[x]) {
                if (d[x] + w < d[y]) {
                    d[y] = d[x] + w;
                    q.emplace(d[y], y);
                }
            }
        }
        return -1;
    }
};