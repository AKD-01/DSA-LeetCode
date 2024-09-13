class Solution {
public:
    vector<int> xorQueries(vector<int>& A, vector<vector<int>>& queries) {
      vector<int> res;
        for (int i = 1; i < A.size(); ++i)
            A[i] ^= A[i - 1];
        for (auto &q: queries)
            res.push_back(q[0] > 0 ? A[q[0] - 1] ^ A[q[1]] : A[q[1]]);
        return res;  
    }
};