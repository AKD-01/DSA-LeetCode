class Solution {
public:
    int minimumCost(vector<int>& nums) {
        nth_element(nums.begin()+1, nums.begin()+2, nums.end());
        return nums[0]+nums[1]+nums[2];
    }
};