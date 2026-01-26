class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& A) {
        sort(A.begin(), A.end());
        int minDiff = INT_MAX;
        vector<vector<int>> res;

        for (int i = 1; i < A.size(); i++) {
            int diff = A[i] - A[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                res.clear();
                res.push_back({A[i - 1], A[i]});
            } else if (diff == minDiff)
                res.push_back({A[i - 1], A[i]});
        }

        return res;
    }
};
