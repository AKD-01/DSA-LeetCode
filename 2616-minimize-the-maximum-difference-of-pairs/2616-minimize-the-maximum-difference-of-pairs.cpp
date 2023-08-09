class Solution {
public:
    int minimizeMax(vector<int>& A, int p) {
       sort(A.begin(), A.end());
        int n = A.size(), left = 0, right = A[n - 1] - A[0];
        while (left < right) {
            int mid = (left + right) / 2, k = 0;
            for (int i = 1; i < n && k < p; ++i) {
                if (A[i] - A[i - 1] <= mid) {
                    k++;
                    i++;
                }
            }
            if (k >= p)
                right = mid;
            else
                left = mid + 1;
        }
        return left; 
    }
};