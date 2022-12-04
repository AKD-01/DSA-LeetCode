class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        long long right_sum = 0;
        for(auto it:nums) right_sum += it;
        int mini = INT_MAX;
        int idx = 0;
        long long left_sum = 0;
        for(int i=0; i<n; i++) {
            left_sum += nums[i];
            right_sum -= nums[i];
            long long first = (left_sum/(i+1));
            long long last = i<n-1 ? (right_sum/(n-i-1)) : 0;
            int diff = abs(first - last);
            if(diff < mini) {
                mini = diff;
                idx = i;
            }
        }
        return idx;
    }
};