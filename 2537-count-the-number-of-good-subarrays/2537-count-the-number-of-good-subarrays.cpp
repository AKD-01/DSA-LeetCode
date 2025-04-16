class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
      int n = nums.size();
        int same = 0, right = -1;
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (int left = 0; left < n; ++left) {
            while (same < k && right + 1 < n) {
                ++right;
                same += cnt[nums[right]];
                ++cnt[nums[right]];
            }
            if (same >= k) {
                ans += n - right;
            }
            --cnt[nums[left]];
            same -= cnt[nums[left]];
        }
        return ans;  
    }
};