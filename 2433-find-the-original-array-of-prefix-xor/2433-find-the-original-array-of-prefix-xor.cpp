class Solution {
public:
    vector<int> findArray(vector<int>& A) {
        for (int i = A.size() - 1; i > 0; --i)
            A[i] ^= A[i - 1];
        return A;
    }
};