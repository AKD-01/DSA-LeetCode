class Solution {
public:
    int appendCharacters(string s, string t) {
       int j = 0, n = s.size(), m = t.size();
        for (int i = 0; i < n && j < m; ++i)
            j += s[i] == t[j];
        return m - j; 
    }
};