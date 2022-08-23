class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        unordered_map<int,bool> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]] = true;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]-diff] && mp[nums[i]+diff])
                count++;
        }
        return count;
    }
};