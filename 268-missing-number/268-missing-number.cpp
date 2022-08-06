class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0,n=nums.size();
        int total=(n*(n+1))/2;
        for(auto it:nums){
            sum+=it;
        }
        return total-sum;
    }
};