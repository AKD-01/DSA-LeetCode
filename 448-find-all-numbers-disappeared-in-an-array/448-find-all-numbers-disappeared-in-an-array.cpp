class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s;
        int n=nums.size();
        vector<int> ans;
        for(auto it: nums){
            s.insert(it);
        }
        for(int i=1;i<=n;i++){
           if (s.find(i)==s.end()) ans.push_back(i);
        }
        return ans;
    }
};