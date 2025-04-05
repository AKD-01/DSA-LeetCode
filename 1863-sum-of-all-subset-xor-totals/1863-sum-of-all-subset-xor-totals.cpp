class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result |= num;
        }
        return result << (nums.size() - 1);
    }
};