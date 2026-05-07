class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        // [value, index]
        using Item = pair<int, int>;
        vector<Item> prevMax(n);

        Item prev = {INT_MIN, -1};
        for (int i = 0; i < n; ++i) {
            if (nums[i] > prev.first) {
                prev = {nums[i], i};
            }
            prevMax[i] = prev;
        }

        auto process = [&](auto& self, int r, int rightMin,
                           int rightMax) -> void {
            auto [pMax, pivotIndex] = prevMax[r];
            int currMax = pMax <= rightMin ? pMax : rightMax;

            int nextRightMin = min(pMax, rightMin);
            for (int i = pivotIndex; i <= r; ++i) {
                ans[i] = currMax;
                nextRightMin = min(nextRightMin, nums[i]);
            }

            if (pivotIndex == 0) {
                return;
            }

            self(self, pivotIndex - 1, nextRightMin, currMax);
        };

        process(process, n - 1, INT_MAX, 0);

        return ans;
    }
};