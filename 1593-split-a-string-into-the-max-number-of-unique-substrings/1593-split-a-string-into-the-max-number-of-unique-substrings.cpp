class Solution {
    void dfs(int i, int n, string &str, unordered_set<string> &s, int &ans) {
        if(i == n) {
            ans = max(ans, (int)s.size());
            return;
        }
        string t;
        for(int j=i; j<n; j++) {
            t += str[j];
            if(s.find(t) == s.end()) {
                s.insert(t);
                dfs(j + 1, n, str, s, ans);
                s.erase(t);
            }
        }
    }
public:
    int maxUniqueSplit(string str) {
        int n = str.size(), ans = 0;
        unordered_set<string> s;
        dfs(0, n, str, s, ans);
        return ans;
    }
};