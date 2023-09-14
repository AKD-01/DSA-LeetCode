class Solution {
private:
    bool dfs(unordered_map<string,vector<string>>& m, vector<string>& res, string s, int n) {
        if(res.size() == n+1) return true;
        if(m[s].size() == 0) return false;

        for(int i = 0; i < m[s].size(); i++) {
            string temp = m[s][i];
            res.push_back(temp);
            m[s].erase(m[s].begin() + i);
            bool x = dfs(m, res, temp, n);

            if(x) return true;
            m[s].insert(m[s].begin()+i, temp);
            res.pop_back();
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        sort(tickets.begin(), tickets.end());
        unordered_map<string,vector<string>> m;

        for(int i = 0; i < n; i++) {
            m[tickets[i][0]].push_back(tickets[i][1]);
        }

        vector<string> res;
        res.push_back("JFK");
        bool x = dfs(m, res, "JFK", n);
        return res;
    }
};