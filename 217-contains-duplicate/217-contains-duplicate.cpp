class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it:nums){
            s.insert(it);
        }
        if(s.size()==nums.size()) return false;
        return true;
    }
};

//TC:O(N)
//SC:O(N)