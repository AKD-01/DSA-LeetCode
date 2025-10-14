class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prev = 0, increaseCount = 1;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] < nums[i]) increaseCount++;
            else {
                prev = increaseCount;
                increaseCount = 1;
            }

            if(increaseCount / 2 >= k || prev / 2 >= k
                || min(prev, increaseCount) >= k) return true;
        }
        return false;
    }
};