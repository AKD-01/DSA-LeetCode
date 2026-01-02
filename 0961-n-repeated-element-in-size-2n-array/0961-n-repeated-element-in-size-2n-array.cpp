class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 0; i < A.size() - 1; ++i)
            if (A[i] == A[i + 1] || (i + 2 < A.size() && A[i] == A[i + 2]))
                return A[i];
        
        return A[0];
    }
};
