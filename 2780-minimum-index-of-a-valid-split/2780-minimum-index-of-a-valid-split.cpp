class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> left, right;
        int n = nums.size();

        for (int num : nums) right[num]++;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            right[num]--;
            left[num]++;

            if (left[num] * 2 > i + 1 && right[num] * 2 > n - i - 1) {
                return i;
            }
        }

        return -1;
    }
};
