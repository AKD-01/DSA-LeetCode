class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long res = 0;
        vector<vector<long long>> d(26, vector<long long>(26, INT_MAX));
        for (int i = 0; i < original.size(); ++i) {
            int s = original[i] - 'a', t = changed[i] - 'a';
            d[s][t] = min(d[s][t], (long long)cost[i]);
        }
        for (int k = 0; k < 26; ++k)
            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < 26; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == target[i])
            continue;
            int s = source[i] - 'a', t = target[i] - 'a';
            if (d[s][t] >= INT_MAX)
                return -1;
            res += d[s][t];
        }
        return res;
    }
};