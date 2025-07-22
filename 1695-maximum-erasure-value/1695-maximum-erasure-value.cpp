class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int frequency[10001]{};
      
        int numsSize = nums.size();
      
        int prefixSum[numsSize + 1];
        prefixSum[0] = 0; 
        for (int i = 0; i < numsSize; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
      
        int maxSum = 0;
      
        int startIndex = 0;
      
        for (int i = 1; i <= numsSize; ++i) {
            int currentValue = nums[i - 1];
            startIndex = max(startIndex, frequency[currentValue]);
            maxSum = max(maxSum, prefixSum[i] - prefixSum[startIndex]);
            frequency[currentValue] = i;
        }
      
        return maxSum;
    }
};
