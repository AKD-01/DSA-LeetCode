class Solution {
public:
    void calc(int ind, vector<int> &store, vector<vector<int>> &ans, vector<int> &nums, int n) {
        if(ind==n) {
            ans.push_back(store);
            return;
        }
        //pick
        store.push_back(nums[ind]);
        calc(ind+1, store, ans, nums, n);
        store.pop_back();
        //Not Pick
        calc(ind+1, store, ans, nums, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> store;
        calc(0,store,ans,nums,n);
        return ans;
    }
};