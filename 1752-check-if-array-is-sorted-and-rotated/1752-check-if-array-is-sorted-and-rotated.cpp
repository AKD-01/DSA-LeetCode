class Solution {
public:
    bool check(vector<int>& nums) {
        //there will be atmost one position that nums[i]>nums[i+1] if array is sorted
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]) count++; //i+1%n is done to compare the first element with the last element i.e nums[n-1] with nums[0].
        }
        return count<=1;
    }
};