class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int> table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int num = 0;
        for (int i = 0; i < s.length() - 1; ++i) {
            if (table[s[i]] < table[s[i + 1]]) {
                num -= table[s[i]];
            } else {
                num += table[s[i]];
            }
        }
        num += table[s.back()];
        return num;
    }
};