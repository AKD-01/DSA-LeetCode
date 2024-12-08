class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int res = 0, max_val = 0;
        priority_queue<pair<int, int>> pq;
        sort(begin(events), end(events));
        for (auto &e : events) {
            for(; !pq.empty() && -pq.top().first < e[0]; pq.pop())
                max_val = max(max_val, pq.top().second);
            res = max(res, max_val + e[2]);
            pq.push({-e[1], e[2]});
        }
        return res; 
    }
};