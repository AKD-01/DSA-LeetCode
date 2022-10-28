class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for(auto str: strs) {
            string t=str;
            sort(t.begin(),t.end());
            um[t].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto val : um) {
            ans.push_back(val.second);
        }
        return ans;
    }
};