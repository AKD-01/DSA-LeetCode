class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int l=0;
        for(int r=1;r<n;r++) {
            if(nums[l]!=nums[r]) l++;
            nums[l]=nums[r];
        }
        return l+1;
    }
};