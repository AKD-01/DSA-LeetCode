class Solution {
public:
    bool canJump(vector<int>& nums) {
    int i = 0;
    int n=nums.size();
    for (int reach = 0; i < n && i <= reach; ++i) reach = max(i + nums[i], reach);
    return i == n;
    }
};