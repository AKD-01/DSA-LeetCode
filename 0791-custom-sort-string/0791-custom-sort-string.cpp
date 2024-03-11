class Solution {
public:
    string customSortString(string order, string str) {
        int cnt[128] = {};
        for (char c : str) ++cnt[c];
        int i = 0;
        for (char c : order) {
            while (cnt[c] > 0) {
                str[i++] = c;
                --cnt[c];
            }
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            while (cnt[c] > 0) {
                str[i++] = c;
                --cnt[c];
            }
        }
        return str;
    }
};