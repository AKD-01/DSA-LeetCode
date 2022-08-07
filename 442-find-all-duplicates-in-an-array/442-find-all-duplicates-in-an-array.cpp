class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(auto it: nums){
            m[it]++;
        }
        for(auto it: m){
            if(it.second==2) ans.push_back(it.first);
        }
        return ans;
    }
};