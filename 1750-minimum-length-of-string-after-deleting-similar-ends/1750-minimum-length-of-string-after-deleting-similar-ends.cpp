class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1, ch = 0;
        while (i < j && s[i] == s[j]) {
            ch = s[i];
            while (i < j && s[i] == ch) ++i;
            while (i < j && s[j] == ch) --j;
        }
        return s[i] == ch ? 0 : j - i + 1; 
    }
};