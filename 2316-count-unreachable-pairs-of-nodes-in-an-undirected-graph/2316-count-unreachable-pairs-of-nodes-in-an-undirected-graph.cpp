class Solution {
public:
   long long dfs(int i, vector<vector<int>> &al, vector<bool> &visited) {
    if (visited[i])
        return 0;
    visited[i] = true;
    return accumulate(begin(al[i]), end(al[i]), 1, [&](int s, int j){ return s + dfs(j, al, visited); });
}
long long countPairs(int n, vector<vector<int>>& edges) {
    long long res = 0;
    vector<vector<int>> al(n);
    vector<bool> visited(n);
    for (auto &e : edges) {
        al[e[0]].push_back(e[1]);
        al[e[1]].push_back(e[0]);
    }
    for (int i = 0; i < al.size(); ++i) {
        auto reached = dfs(i, al, visited);
        res += (n - reached) * reached;
        n -= reached;
    }
    return res;
}
};