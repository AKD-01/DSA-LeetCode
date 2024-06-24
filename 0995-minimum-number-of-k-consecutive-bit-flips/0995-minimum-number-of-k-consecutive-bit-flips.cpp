class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int cur = 0, res = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            if (i >= K && A[i - K] > 1) {
                cur--;
                A[i - K] -= 2;
            }
            if (cur % 2 == A[i]) {
                if (i + K > n) return -1;
                A[i] += 2;
                cur++;
                res++;
            }
        }
        return res;
    }
};