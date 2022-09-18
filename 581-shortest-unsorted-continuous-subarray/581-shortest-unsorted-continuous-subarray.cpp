class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy(nums);
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int r=n-1;
        int count=0;
        while(l<n && nums[l]==copy[l]) {
            l++;
        }
        while(r>=0 && nums[r]==copy[r]) {
            r--;
        }
        if(l==n) {
            return 0;
        }
        else {
            for(int i=l;i<=r;i++) {
                count++;
            }
        }
        return count;
    }
};