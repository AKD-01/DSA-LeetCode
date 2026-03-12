struct Edge {
    int u, v, w, type;
};

class DSU {
public:
    vector<int> parent;

    DSU(const vector<int>& p) : parent(p) {}

    int find(int x) {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    void join(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[px] = py;
        }
    }
};

const int MAX_STABILITY = 2e5;

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int ans = -1;

        if (edges.size() < n - 1) {
            return -1;
        }

        vector<Edge> sortedEdges;
        sortedEdges.reserve(edges.size());
        for (const auto& edge : edges) {
            sortedEdges.push_back({edge[0], edge[1], edge[2], edge[3]});
        }

        vector<Edge> mustEdges;
        vector<Edge> optionalEdges;

        for (const auto& edge : sortedEdges) {
            if (edge.type == 1) {
                mustEdges.push_back(edge);
            } else {
                optionalEdges.push_back(edge);
            }
        }

        if (mustEdges.size() > n - 1) {
            return -1;
        }
        sort(optionalEdges.begin(), optionalEdges.end(),
             [](const Edge& a, const Edge& b) { return b.w < a.w; });

        int selectedInit = 0;
        int mustMinStability = MAX_STABILITY;
        vector<int> initialParent(n);
        iota(initialParent.begin(), initialParent.end(), 0);
        DSU dsuInit(initialParent);

        for (const auto& edge : mustEdges) {
            if (dsuInit.find(edge.u) == dsuInit.find(edge.v) ||
                selectedInit == n - 1) {
                return -1;
            }

            dsuInit.join(edge.u, edge.v);
            selectedInit++;
            mustMinStability = std::min(mustMinStability, edge.w);
        }

        int l = 0;
        int r = mustMinStability;

        while (l < r) {
            int mid = l + ((r - l + 1) >> 1);

            DSU dsu(dsuInit.parent);

            int selected = selectedInit;
            int doubledCount = 0;

            for (const auto& edge : optionalEdges) {
                if (dsu.find(edge.u) == dsu.find(edge.v)) {
                    continue;
                }

                if (edge.w >= mid) {
                    dsu.join(edge.u, edge.v);
                    selected++;
                } else if (doubledCount < k && edge.w * 2 >= mid) {
                    doubledCount++;
                    dsu.join(edge.u, edge.v);
                    selected++;
                } else {
                    break;
                }

                if (selected == n - 1) {
                    break;
                }
            }

            if (selected != n - 1) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid;
            }
        }

        return ans;
    }
};