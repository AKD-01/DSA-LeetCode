class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]==1) ans=nums[i];
        }
        return ans;
    }
};