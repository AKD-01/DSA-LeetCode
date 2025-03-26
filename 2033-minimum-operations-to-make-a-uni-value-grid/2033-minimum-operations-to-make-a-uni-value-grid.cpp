class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int ops = 0;

        for (auto& row : grid) {
            for (int num : row) {
                nums.push_back(num);
            }
        }

        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int median = nums[n / 2];

        for (int num : nums) {
            if (num % x != median % x) return -1;
            ops += abs(median - num) / x;
        }

        return ops;
    }
};
