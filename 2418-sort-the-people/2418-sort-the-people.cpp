class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string>mp;
        vector<string>v;
        for(int i=0; i < size(names); i++)
            mp[heights[i]] = names[i];
        for (auto i = mp.rbegin(); i != mp.rend(); ++i) v.push_back(i->second);
        return v;
    }
};