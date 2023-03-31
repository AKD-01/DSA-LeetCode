class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //Brute Force Approach TC-O(N)+O(N/2) SC-O(N)
        int n=nums.size();
        vector<int> p; 
        vector<int> neg;
        for(int i=0; i<n; i++) {
            if(nums[i]>0) p.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        for(int i=0; i<n/2; i++) {
            nums[2*i] = p[i];
            nums[2*i+1] = neg[i];
        }
        return nums;
    }
};