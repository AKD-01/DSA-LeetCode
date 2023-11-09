class Solution {
public:
    int countHomogenous(string s) {
        int res = 0, cur = 0, count = 0, mod = 1e9 + 7;
        for (int a: s) {
            count = a == cur ? count + 1 : 1;
            cur = a;
            res = (res + count) % mod;
        }
        return res;
    }
};