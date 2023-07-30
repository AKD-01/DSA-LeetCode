class Solution {
public:
    int strangePrinter(string s) {
       vector<vector<int>> d(s.size()+1, vector<int>(s.size()+1));
        for (int len = 0; len < s.size(); ++len) {
            for (int start = 0; start < s.size() - len; ++start) {
                int end = start + len;
                d[start][end] = len + 1;
                for (int k = start + 1; k <= end; ++k) {
                    int steps = d[start][k-1] + d[k][end] - (s[k-1] == s[end] ? 1 : 0);
                    d[start][end] = min(d[start][end], steps);
                }
            }
        }
        return d[0][s.size()-1];
    }
};