class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> numsPos;
        for (int i = 0; i < n; i++) {
            numsPos[nums[i]].push_back(i);
        }
        for (auto& [_, pos] : numsPos) {
            int x = pos[0];
            pos.insert(pos.begin(), pos.back() - n);
            pos.push_back(x + n);
        }
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            int x = nums[queries[i]];
            if (numsPos[x].size() == 3) {
                queries[i] = -1;
                continue;
            }
            int pos =
                lower_bound(numsPos[x].begin(), numsPos[x].end(), queries[i]) -
                numsPos[x].begin();
            queries[i] = min(numsPos[x][pos + 1] - numsPos[x][pos],
                             numsPos[x][pos] - numsPos[x][pos - 1]);
        }
        return queries;
    }
};