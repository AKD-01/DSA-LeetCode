class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        auto beg = nums.begin(), end = nums.end();
        sort(beg, end);
        for(int i = 0; i < nums.size()-1; ++i){
            ans += upper_bound(beg + i+1, end, upper - nums[i]) - lower_bound(beg + i+1, end, lower - nums[i]);
        }
        return ans;
    }
};