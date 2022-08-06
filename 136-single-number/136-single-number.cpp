class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans=0;
        for(auto it:nums) {
            m[it]++;
        }
        for(auto it:nums){
            if(m[it]==1) ans=it;
        }
        return ans;
    }
};