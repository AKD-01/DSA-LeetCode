class Solution {
public:
    bool OutofOrder(vector<int> nums, int i) {
        int x=nums[i];
        if(i==0) {
            return x>nums[1];
        }
        if(i==nums.size()-1) {
            return x<nums[i-1];
        }
        return x>nums[i+1] or x<nums[i-1];
    }
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return 0;
        int smallest=INT_MAX;
        int largest=INT_MIN;
        for(int i=0;i<nums.size();i++) {
            int x=nums[i];
            if(OutofOrder(nums,i)) {
                smallest=min(smallest,x);
                largest=max(largest,x);
            }
        }
        if(smallest==INT_MAX) return 0;
        int left=0;
        while(smallest>=nums[left]) {
            left++;
        }
        int right=nums.size()-1;
        while(largest<=nums[right]) {
            right--;
        }
       return right-left+1;
    }
};

/* 
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
*/