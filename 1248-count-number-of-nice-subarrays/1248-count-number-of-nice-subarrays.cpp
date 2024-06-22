class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int n = nums.size();
        int ans = 0,odd = 0,cnt = 0;
        int l = 0,r = 0;
        while(r<n)
        {
            if(nums[r]%2 != 0)
            {
                odd++;
                cnt = 0;
            }
            while(odd == k)
            {
                ++cnt;
                odd -= nums[l++]&1; 
            }
            ans += cnt;
            r++;
        }
        return ans; 
    }
};