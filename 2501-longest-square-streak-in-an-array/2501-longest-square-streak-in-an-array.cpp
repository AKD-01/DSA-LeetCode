class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
       sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>dp(n, 0);
        dp[n - 1] = 1;
        int mxLen = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            long long target = (long long)nums[i] * nums[i];
            int low = i + 1, high = n - 1;
            int pos = -1;
            while(low <= high)
            {
                int mid = low + (high - low) / 2;
                if (nums[mid] == target) { pos = mid; break; }
                else if (nums[mid] < target) low = mid + 1;
                else if (nums[mid] > target) high = mid - 1;
            }
            int currLen;
            if (pos == -1) currLen = 1;
            else currLen = 1 + dp[pos];
            dp[i] = currLen;
            mxLen = max(dp[i], mxLen);
        }
        if (mxLen == 1) return -1;
        return mxLen;  
    }
};