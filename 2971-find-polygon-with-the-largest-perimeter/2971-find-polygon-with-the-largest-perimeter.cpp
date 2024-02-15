class Solution {
public:
    long long largestPerimeter(vector<int>& A) {
       sort(A.begin(), A.end());
        long long res = -1, cur = 0;
        for (int i = 0; i < A.size(); ++i)
            if ((cur += A[i]) > A[i] * 2)
                res = cur;
        return res; 
    }
};