class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1000000007;
        long long A = 6, B = 6;

        for (int i = 2; i <= n; i++) {
            long long newA = (2 * A + 2 * B) % MOD;
            long long newB = (2 * A + 3 * B) % MOD;
            A = newA;
            B = newB;
        }

        return (A + B) % MOD;
    }
};