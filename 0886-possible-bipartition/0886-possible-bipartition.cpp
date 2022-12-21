class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> adj[N+1];
        for(auto dislike : dislikes) {
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }

        vector<int> color(N+1, 0);
        function<bool(int, int)> dfs = [&](int cur, int col) {
            if(color[cur] != 0) 
                return color[cur] == col;
            color[cur] = col;
            for(auto nxt : adj[cur]) 
                if(!dfs(nxt, -col)) 
                    return false;
            return true;
        };

        for(int i = 1; i <= N; i++) {
            if(color[i] == 0 && !dfs(i, 1)) 
                return false;
        }
        return true;        
    }
};