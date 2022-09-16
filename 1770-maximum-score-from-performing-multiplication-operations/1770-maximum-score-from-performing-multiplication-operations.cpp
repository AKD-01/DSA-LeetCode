class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<int> cur(multipliers.size()+1,0),next(multipliers.size()+1,0);
        for(int i=multipliers.size()-1;i>=0;i--) {
            for(int j=multipliers.size()-i-1;j>=0;j--) {
                int s=nums[i]*multipliers[i+j]+next[j];
                int e=nums[nums.size()-j-1]*multipliers[i+j]+cur[j+1];
                cur[j]=max(s,e);
            }
            next=cur;
        }
     return next[0];
    }        
};