class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (str1[i - 1] == str2[j - 1]) ? dp[i - 1][j - 1] + 1 
                                                         : min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }

        string res = "";
        int i = m, j = n;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                res += str1[i - 1];
                i--, j--;
            } else if (dp[i - 1][j] < dp[i][j - 1]) {
                res += str1[i - 1];
                i--;
            } else {
                res += str2[j - 1];
                j--;
            }
        }

        while (i > 0) res += str1[--i];
        while (j > 0) res += str2[--j];

        reverse(res.begin(), res.end());
        return res;
    }
};
