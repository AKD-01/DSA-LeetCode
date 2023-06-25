class Solution {
public:
    int dp[101][201] = {};
    int countRoutes(vector<int>& locs, int i, int finish, int f) {
       if (!dp[i][f]) {
        dp[i][f] = 1 + (i == finish);
        for (int j = 0; j < locs.size(); ++j)
            if (i != j && f >= abs(locs[i] - locs[j]))
                dp[i][f] = (dp[i][f] + countRoutes(locs, j, finish, f - abs(locs[i] - locs[j]))) % 1000000007;
    }
    return dp[i][f] - 1; 
    }
};