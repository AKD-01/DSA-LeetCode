class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for(int i=1; i<nums.size(); ++i)
            nums[i] += nums[i-1];
        for(int& q: queries)
            res.push_back(upper_bound(nums.begin(), nums.end(), q) - nums.begin());
        return res;
    }
};