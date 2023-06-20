class Solution {
public:
    vector<int> getAverages(vector<int>& A, int k) {
        int N = A.size(), len = 2 * k + 1;
        vector<int> ans(N, -1);
        if (N < len) return ans; // If the array is too short to cover a window, return all -1s
        vector<long> sum(N + 1);
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];
        for (int i = k; i + k < N; ++i) ans[i] = (sum[i + k + 1] - sum[i - k]) / len;
        return ans;
    }
};