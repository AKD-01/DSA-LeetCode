class Solution {
private:
    int len(int left, int right, int n) {
        if(left <= right) {
            return right - left + 1;
        } else {
            return (n - left) + (right + 1);
        }
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, ans = INT_MAX;
        int ones = 0, total = 0;
        for(int i = 0; i < n; ++i) {
            total += (nums[i] ==1);
        }
        if(total == 0) return 0;

        while(left < n) {
            ones += (nums[right] == 1);
            if(len(left, right, n) == total) {
                ans = min(ans, total - ones);
                ones -= (nums[left] == 1);
                ++left;
            }
            right = (right + 1) % n;
        }
        return ans;
    }
};