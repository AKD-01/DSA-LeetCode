class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, res = 0;
    for (auto &r : bank) {
        int cur = count(begin(r), end(r), '1');
        if (cur) {
            res += prev * cur;
            prev = cur;
        }
    }
    return res;
    }
};