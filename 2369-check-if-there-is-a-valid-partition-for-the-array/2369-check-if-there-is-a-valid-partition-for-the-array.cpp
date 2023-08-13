class Solution {
public:
    bool validPartition(vector<int>& n) {
        bool dp[4] = {true, false, n[0] == n[1], false};
        for (int i = 2; i < n.size(); ++i) {
        bool two = n[i] == n[i - 1];
        bool three = (two && n[i] == n[i - 2]) || (n[i] - 1 == n[i - 1] && n[i] - 2 == n[i - 2]);
        dp[(i + 1) % 4] = (dp[(i - 1) % 4] && two) || (dp[(i - 2) % 4] && three);
    }
    return dp[n.size() % 4];
    }
};