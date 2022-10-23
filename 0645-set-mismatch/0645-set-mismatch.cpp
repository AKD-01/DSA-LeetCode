class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=1;i<=nums.size();i++) {
            m[i]=0;
        }
        for(int val: nums) {
            m[val]++;
        }
        for(auto val: m) {
            if(val.second==2) 
            {
                ans.push_back(val.first);
                break;
            }
        }
        for(auto val: m) {
            if(val.second==0) 
            {
                ans.push_back(val.first);
                break;
            }
        }
        return ans;
    }
};