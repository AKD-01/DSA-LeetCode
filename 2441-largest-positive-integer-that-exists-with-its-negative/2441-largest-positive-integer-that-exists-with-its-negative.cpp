class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low=0, high=nums.size()-1;
        while(low < high) {
            if((nums[low] + nums[high]) == 0) {
                return  nums[high];
            }
            else if((nums[low] + nums[high]) < 0) low++;
            else high--;
        }
        return -1;  
    }
};