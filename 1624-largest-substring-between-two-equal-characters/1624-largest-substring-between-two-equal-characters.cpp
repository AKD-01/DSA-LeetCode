class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int idx[26] = {}, res = -1;
        for (auto i = 0; i < s.size(); ++i) {
        if (idx[s[i] - 'a'] == 0)
            idx[s[i] - 'a'] = i + 1;
        res = max(res, i - idx[s[i] - 'a']);
    }
    return res;
    }
};