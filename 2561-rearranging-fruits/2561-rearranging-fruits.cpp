class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int m = INT_MAX;
        unordered_map<int, int> frequency_map;
        for (int b1 : basket1) {
            frequency_map[b1]++;
            m = min(m, b1);
        }
        for (int b2 : basket2) {
            frequency_map[b2]--;
            m = min(m, b2);
        }
        vector<int> merge;
        for (auto [k, c] : frequency_map) {
            if (c % 2 != 0) {
                return -1;
            }
            for (int i = 0; i < abs(c) / 2; ++i) {
                merge.push_back(k);
            }
        }
        nth_element(merge.begin(), merge.begin() + merge.size() / 2,
                    merge.end());
        return accumulate(merge.begin(), merge.begin() + merge.size() / 2, 0ll,
                          [&](long long res, int x) -> long long {
                              return res + min(2 * m, x);
                          });
    }
};