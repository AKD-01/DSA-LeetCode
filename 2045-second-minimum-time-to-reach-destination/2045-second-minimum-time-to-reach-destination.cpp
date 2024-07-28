class Solution {
public:
    vector<vector<int> > adj;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        adj.resize(n + 1);
        int firstArrivedTime = INT_MAX;
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue< vector<int> > q;
        q.push({1, 0});
        vector<int> visTime(n + 1, INT_MAX);
        vector<int> visCount(n + 1, 0);
        while(q.size()) {
            auto p = q.front(); q.pop();
            int node = p[0], t = p[1];
            for(int next : adj[node]) {
                int t2 = t;
                bool isRed = (t2 / change) % 2;
                if(isRed) t2 += change - t2 % change;
                t2 += time;
                if(next == n && firstArrivedTime == INT_MAX) firstArrivedTime = t2;
                if(next == n && t2 > firstArrivedTime) return t2;
                if(visTime[next] != t2 && visCount[next] <= 1) { //at most revisit one time.
                    visTime[next] = t2;
                    visCount[next]++;
                    q.push({next, t2});
                }
            }
        }
        return -1;
    }
};
