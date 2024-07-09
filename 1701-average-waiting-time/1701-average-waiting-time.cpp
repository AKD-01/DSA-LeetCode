class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& C) {
        double wait = 0, cur = 0;
        for (auto& a: C) {
            cur = max(cur, 1.0 * a[0]) + a[1];
            wait += cur - a[0];
        }
        return 1.0 * wait / C.size();
    }
};