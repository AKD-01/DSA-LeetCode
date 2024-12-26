class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int x: nums)
            sum += x;
        if (abs(target) > sum || (sum + target) % 2 != 0){ 
            return 0;
        }
        int s1 = (sum + target)/2;
        int ans = subsetCount(nums,s1);
        return ans;
    }
    
    int subsetCount(vector<int>& nums, int s1){
        int n = nums.size();
        int t[n+1][s1+1];
        t[0][0] = 1;
        for(int i=1;i<s1+1;i++)
            t[0][i] = 0;
        for(int i=1;i<n+1;i++)
            for(int j=0;j<s1+1;j++){
                if(nums[i-1] > j)
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
            }
        
        return t[n][s1];
    }
};