class Solution {
public:
    long long dfs(int i, int prev, int depth, int seats, vector<vector<int>>& al, long long &res) {
    long long riders = 1;
    for (int j : al[i])
        if (j != prev)
            riders += dfs(j, i, depth + 1, seats, al, res);
    if (depth == 0)
        return res;
    res += (riders / seats) * depth + (riders % seats ? 1 : 0);
    return riders % seats;
}
long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    vector<vector<int>> al(roads.size() + 1);
    for (auto &r : roads) {
        al[r[0]].push_back(r[1]);
        al[r[1]].push_back(r[0]);
    }
    long long res = 0;
    return dfs(0, -1, 0, seats, al, res);
}
};