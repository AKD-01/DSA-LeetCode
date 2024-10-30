class Solution {
public:
    int minimumMountainRemovals(vector<int>& A) {
        int N = A.size(), ans = N;
        vector<int> a(N), b(N), v;
        for (int i = 0 ; i < N; ++i) {
            int x = A[i];
            auto it = lower_bound(begin(v), end(v), x);
            a[i] = it - begin(v);
            if (it != end(v)) *it = x;
            else v.push_back(x);
        }
        v.clear();
        for (int i = N - 1; i >= 0; --i) {
            int x = A[i];
            auto it = lower_bound(begin(v), end(v), x) ;
            b[i] = it - begin(v); 
            if (it != end(v)) *it = x;
            else v.push_back(x);
        }
        for (int i = 1; i < N; ++i) {
            if (a[i] && b[i]) ans = min(ans, N - (a[i] + b[i] + 1));
        }
        return ans;
    }
};