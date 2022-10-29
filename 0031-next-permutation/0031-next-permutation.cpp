class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), k,l;
        for(k=n-2;k>=0;k--) {
            if(nums[k]<nums[k+1]) break;
        }
        if(k<0) {
            reverse(nums.begin(),nums.end());
            //example: 5,4,3,2,1 so the answer in that case will be 1,2,3,4,5
        }
        else {
            for(l=n-1;l>k;l--) {
                if(nums[l]>nums[k]) break;
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};