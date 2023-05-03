class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& A, vector<int>& B) {
        unordered_set<int> sa(begin(A), end(A)), sb(begin(B), end(B));
        vector<vector<int>> ans(2);
        for (int n : sa) {
            if (sb.count(n) == 0) ans[0].push_back(n);
        }
        for (int n : sb) {
            if (sa.count(n) == 0) ans[1].push_back(n);
        }
        return ans; 
    }
};