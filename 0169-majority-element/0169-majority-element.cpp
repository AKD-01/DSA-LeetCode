class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxi=INT_MIN;
        for(int val : nums) {
            m[val]++;
        }
        for(auto v : m) {
            maxi=max(maxi,v.second);
        }
        for(auto v: m) {
            if(v.second==maxi) return v.first;
        }
        return 0;
    }
};