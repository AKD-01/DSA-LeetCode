class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0, maxi=0, n=nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i]==1) {
                count++;
                maxi=max(maxi,count);
            }
            else {
                count=0;
            }
        }
        return maxi;
    }
};