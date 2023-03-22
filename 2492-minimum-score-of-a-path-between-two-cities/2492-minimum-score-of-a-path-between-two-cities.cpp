class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,unordered_map<int,int>> graph;
        for (auto r : roads)
            graph[r[0]][r[1]] = graph[r[1]][r[0]] = r[2];
        
        unordered_set<int> vis;
        
        function<int(int)> dfs;
        dfs = [&](int n) -> int
        {
            int res = INT_MAX;
            vis.insert(n);
            
            for (auto[adj, scr] : graph[n])
            {
                if (!vis.count(adj))
                    res = min(res, dfs(adj));
                res = min(res, scr);
            }
            
            return res;
        };
        
        return dfs(1);
    }
};