class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            int n = x;
            int p = 0, q = 0, cnt = 0;

            for (int i = 2; i * i <= n && cnt <= 2; i++) {
                if (n % i == 0) {
                    cnt++;
                    if (cnt == 1) p = i;
                    else q = i;
                    while (n % i == 0) n /= i;
                }
            }

            if (n > 1) {
                cnt++;
                if (cnt == 1) p = n;
                else q = n;
            }

            if (cnt == 2 && 1LL * p * q == x)
                ans += 1 + p + q + x;

            else if (cnt == 1 && 1LL * p * p * p == x)
                ans += 1 + p + p * p + x;
        }
        return ans;
    }
};