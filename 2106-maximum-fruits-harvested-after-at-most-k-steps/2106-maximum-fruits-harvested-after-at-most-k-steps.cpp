class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> sum(n + 1);
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + fruits[i][1];
            indices[i] = fruits[i][0];
        }
        int ans = 0;
        for (int x = 0; x <= k / 2; x++) {
            /* move left x steps, then move right k - x steps. */
            int y = k - 2 * x;
            int left = startPos - x;
            int right = startPos + y;
            int start = lower_bound(indices.begin(), indices.end(), left) -
                        indices.begin();
            int end = upper_bound(indices.begin(), indices.end(), right) -
                      indices.begin();
            ans = max(ans, sum[end] - sum[start]);
            /* move right x steps, then move left k - x steps. */
            y = k - 2 * x;
            left = startPos - y;
            right = startPos + x;
            start = lower_bound(indices.begin(), indices.end(), left) -
                    indices.begin();
            end = upper_bound(indices.begin(), indices.end(), right) -
                  indices.begin();
            ans = max(ans, sum[end] - sum[start]);
        }
        return ans;
    }
};