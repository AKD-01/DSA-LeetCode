class Solution {
public:
    int totalMoney(int n) {
        int f = n / 7, d = n % 7;
        return (49 + 7 * f) * f / 2 + (2 * f + d + 1) * d / 2;
    }
};