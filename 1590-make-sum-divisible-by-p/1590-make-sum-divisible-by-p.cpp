class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalSum =
            accumulate(nums.begin(), nums.end(), 0LL);   
        if (totalSum % p == 0) return 0;

        int minLen = n;  

        for (int start = 0; start < n; ++start) {
            long long subSum = 0;  
            for (int end = start; end < n; ++end) {
                subSum += nums[end];  
                long long remainingSum = (totalSum - subSum) % p;

                if (remainingSum == 0) {
                    minLen = min(minLen,
                                 end - start + 1);  
                }
            }
        }
        return minLen == n ? -1 : minLen;
    }
};