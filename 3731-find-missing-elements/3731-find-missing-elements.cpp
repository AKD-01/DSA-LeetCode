class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        ranges::sort(nums);
        vector<int> ans;
        for (int i = 0; i < n - 1; i++) {
            for (int j = nums[i] + 1; j < nums[i + 1]; j++) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};