class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Brute force approach TC-O(2N) SC-O(x) x-non zero elements
        vector<int> temp;
        int n =  nums.size();
        for(int val: nums) {
            if(val!=0) temp.push_back(val);
        }
        int s=temp.size();
        for(int i=0; i<s; i++) {
            nums[i] = temp[i];
        }
        for(int i=s; i<n; i++) {
            nums[i]=0;
        }
    }
};