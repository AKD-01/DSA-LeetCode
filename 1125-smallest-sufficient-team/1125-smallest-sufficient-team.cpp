class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<int, vector<int>> dp;
        dp.reserve(1 << n); // reserve space and avoid hash collisions
        dp[0] = {};
        unordered_map<string, int> skill_index;
        for (int i = 0; i < req_skills.size(); ++i)
            skill_index[req_skills[i]] = i;
        for (int i = 0; i < people.size(); ++i) {
            int cur_skill = 0;
            for (auto& skill: people[i])
                cur_skill |= 1 << skill_index[skill];
            for (auto it = dp.begin(); it != dp.end(); ++it) {
                int comb = it->first | cur_skill;
                if (dp.find(comb) == dp.end() || dp[comb].size() > 1 + dp[it->first].size()) {
                    dp[comb] = it->second;
                    dp[comb].push_back(i);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};