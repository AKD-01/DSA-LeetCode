class Solution {
public:
    int singleNumber(vector<int>& nums) {
    //Refer gfg for brute approach and better approach
    //Optimal approach which takes linear runtime complexity and use only constant extra space is using XOR
        int xor1=0, n=nums.size();
        for(int i=0; i<n; i++) {
            xor1 = xor1 ^ nums[i];
        }
        return xor1;
    }
};