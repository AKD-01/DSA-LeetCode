class Solution {
public:
    int binaryGap(int n) {
        if (__builtin_popcount(n) == 1) return 0;
        n >>= __builtin_ctz(n);
        int maxGap = 0, gap = 0;

        while (n) {
            if (n & 1) {
                maxGap = max(maxGap, gap);
                gap = 0;
            } else
                gap++;
            n >>= 1;
        }

        return maxGap + 1;
    }
};