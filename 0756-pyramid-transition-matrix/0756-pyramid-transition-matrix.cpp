class Solution {
public:
    vector<string> gen_neighbor(const string& node,
                                unordered_map<string, unordered_set<char>>& mp) {
        vector<string> res{""};
        int n = node.size();

        for (int i = 1; i < n; i++) {
            string key;
            key.push_back(node[i - 1]);
            key.push_back(node[i]);

            if (mp.count(key) == 0) {
                return {};
            }

            vector<string> newRes;
            for (const string& a : res) {
                for (char c : mp[key]) {
                    newRes.push_back(a + c);
                }
            }
            res.swap(newRes);
        }
        return res;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, unordered_set<char>> mp;
        for (const string& s : allowed) {
            string key;
            key.push_back(s[0]);
            key.push_back(s[1]);
            mp[key].insert(s[2]);
        }

        unordered_set<string> visited;

        function<bool(const string&)> dfs = [&](const string& node) -> bool {
            if (node.size() == 1) {
                return true;
            }
            if (visited.count(node)) {
                return false;
            }

            for (const string& nxt : gen_neighbor(node, mp)) {
                if (dfs(nxt)) {
                    return true;
                }
            }

            visited.insert(node);
            return false;
        };

        return dfs(bottom);
    }
};