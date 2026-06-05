class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        using ll = long long;
        auto solve = [&](ll num) -> ll {
            if (num < 100) {
                return 0;
            }
            string s = to_string(num);
            int n = s.size();

            
            ll memo_cnt[16][10][10];
            
            ll memo_sum[16][10][10];
            memset(memo_cnt, -1, sizeof(memo_cnt));
            memset(memo_sum, -1, sizeof(memo_sum));

            auto dfs = [&](this auto&& dfs, int pos, int prev, int curr,
                           bool isLimit, bool isLeading) -> pair<ll, ll> {
                if (pos == n) {
                    return {1, 0};
                }
                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    if (memo_cnt[pos][prev][curr] != -1) {
                        return {memo_cnt[pos][prev][curr],
                                memo_sum[pos][prev][curr]};
                    }
                }

                ll cnt = 0, sum = 0;
                int up = isLimit ? s[pos] - '0' : 9;
                for (int digit = 0; digit <= up; ++digit) {
                    bool newLeading = isLeading && (digit == 0);
                    int newPrev = curr;
                    int newCurr = newLeading ? -1 : digit;
                    auto [subCnt, subSum] =
                        dfs(pos + 1, newPrev, newCurr, isLimit && (digit == up),
                            newLeading);
                    if (!newLeading && prev >= 0 && curr >= 0) {
                        if ((prev < curr && curr > digit) ||
                            (prev > curr && curr < digit)) {
                            sum += subCnt;
                        }
                    }

                    cnt += subCnt;
                    sum += subSum;
                }

                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    memo_cnt[pos][prev][curr] = cnt;
                    memo_sum[pos][prev][curr] = sum;
                }

                return {cnt, sum};
            };

            auto [_, totalSum] = dfs(0, -1, -1, true, true);
            return totalSum;
        };

        return solve(num2) - solve(num1 - 1);
    }
};