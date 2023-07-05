class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int i = 0, j, k = 1;
        for (j = 0; j < A.size(); ++j) {
            if (A[j] == 0) k--;
            if (k < 0 && A[i++] == 0) k++;
        }
        return j - i - 1;
    }
};