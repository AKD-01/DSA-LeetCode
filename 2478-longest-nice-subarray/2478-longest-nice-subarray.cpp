class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int bits = 0, left = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while ((bits & nums[right]) != 0) {
                bits ^= nums[left++];
            }
            bits |= nums[right];
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
