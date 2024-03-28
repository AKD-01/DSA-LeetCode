class Solution {
public:
    int maxSubarrayLength(vector<int>& A, int k) {
       unordered_map<int, int> count;
        int res = 0, i = 0, n = A.size();
        for (int j = 0; j < n; ++j) {   
            count[A[j]]++;
            while (count[A[j]] > k)
                count[A[i++]]--;
            res = max(res, j - i + 1);
        }
        return res; 
    }
};