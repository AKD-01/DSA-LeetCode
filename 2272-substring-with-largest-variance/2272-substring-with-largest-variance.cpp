class Solution {
public:
    int largestVariance(string s) {
      int res = 0;
    unordered_set<char> unique(begin(s), end(s));
    for (char a : unique)
        for (char b : unique) {
            int var = 0, has_b = 0, first_b = 0;
            for (auto ch : s) {
                var += ch == a;
                if (ch == b) {
                    has_b = true;
                    if (first_b && var >= 0)
                        first_b = false;
                    else if (--var < 0) {
                        first_b = true;
                        var = -1;
                    }
                }
                res = max(res, has_b ? var : 0);
            }
        }
    return res;  
    }
};