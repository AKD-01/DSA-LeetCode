class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), a=0, res=0, k=pow(2, maximumBit)-1;
        vector<int> ans; 
        for(int i=0; i<n; i++)
            a^=nums[i];
        for(int i=n-1; i>=0; i--)
        {
            res = a;
            ans.push_back(res^k);
            a^=nums[i];
        }
        return ans; 
    }
};