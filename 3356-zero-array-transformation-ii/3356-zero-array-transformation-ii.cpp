class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, ops = 0;
        vector<int> diff(n + 1);

        for (int i = 0; i < n; i++) {
            while (sum + diff[i] < nums[i]) {
                if (++ops > queries.size()) return -1;
                int l = queries[ops - 1][0], r = queries[ops - 1][1], v = queries[ops - 1][2];
                if (r >= i) {
                    diff[max(l, i)] += v;
                    diff[r + 1] -= v;
                }
            }
            sum += diff[i];
        }
        return ops;
    }
};
