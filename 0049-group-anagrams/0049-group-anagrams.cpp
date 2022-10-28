class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : m) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};