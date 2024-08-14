class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
        int n = nums.size(), low = 0, high = 1000000;
        while (low < high) {
            int mid = (low + high)/2, cnt = 0;
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n && nums[j]-nums[i] <= mid) j++;
                cnt += j-i-1;
            }
            if (cnt < k) 
                low = mid+1;
            else
                high = mid;
        }
        return low; 
    }
};