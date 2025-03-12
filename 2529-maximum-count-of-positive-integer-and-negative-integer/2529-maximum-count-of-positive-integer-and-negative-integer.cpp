class Solution {
private:
    int lower(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, idx = nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < 0) left = mid + 1;
            else {
                right = mid - 1;
                idx = mid;
            }
        }
        return idx;
    }

    int upper(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, idx = nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= 0) left = mid + 1;
            else {
                right = mid - 1;
                idx = mid;
            }
        }
        return idx;
    }

public:
    int maximumCount(vector<int>& nums) {
        int positiveCount = nums.size() - upper(nums);
        int negativeCount = lower(nums);
        return max(positiveCount, negativeCount);
    }
};
