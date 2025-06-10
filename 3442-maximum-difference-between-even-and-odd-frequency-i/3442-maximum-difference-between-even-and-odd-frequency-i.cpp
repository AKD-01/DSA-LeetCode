class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> c;
        for (char ch : s) {
            ++c[ch];
        }
        int maxOdd = 1, minEven = s.size();
        for (const auto& [_, value] : c) {
            if (value % 2 == 1) {
                maxOdd = max(maxOdd, value);
            } else {
                minEven = min(minEven, value);
            }
        }
        return maxOdd - minEven;
    }
};