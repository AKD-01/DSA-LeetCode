class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> m;
        for(auto& e: paths)     m[e[0]] = e[1];
        string cur(paths[0][0]);
        while(m.count(cur))
            cur = m[cur];
        return cur;
    }
};