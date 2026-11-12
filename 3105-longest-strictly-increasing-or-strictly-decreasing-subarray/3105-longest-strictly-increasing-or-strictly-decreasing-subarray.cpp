class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int best = 1, up = 1, down = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            up = nums[i - 1] < nums[i] ? up + 1 : 1;  // increasing streak ending at nums[i]
            down = nums[i - 1] > nums[i] ? down + 1 : 1;  // decreasing streak ending at nums[i]
            best = max({best, up, down});
        }
        return best;
    }
};