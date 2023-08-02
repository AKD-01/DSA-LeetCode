class Solution {
public:
    void func(int pos, vector<int> &nums, vector<vector<int>> &ans) {
        if(pos>=nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=pos; i<nums.size(); i++) {
            swap(nums[i],nums[pos]);
            func(pos+1,nums,ans);
            swap(nums[i],nums[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        func(0,nums,ans);
        return ans;
    }
};