class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;             // for storing the final answer (Total no. of subarrays)
        long long cnt = 0;             // for counting the consecutive 0's
        for(int i=0;i<nums.size();i++)
        {
            // wherever we find 0 just increase cnt by 1 and sum up to ans
            if(nums[i]==0)               
            {
                cnt++;
                ans += cnt;
            }
            
            // if it is non 0 them make 0 count 0
            else
            {
                cnt = 0;
            }
        }
        return ans;
    }
};