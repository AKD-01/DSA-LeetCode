class Solution {
public:
    long long maximumValueSum(vector<int>& A, int k, vector<vector<int>>& edges) {
        long long res = 0;
        int d = 1 << 30, c = 0;
        for (int a : A) {
            int b = a ^ k;
            res += max(a, b);
            c ^= a < b;
            d = min(d, abs(a - b));
        }
        return res - d * c;
    }
};