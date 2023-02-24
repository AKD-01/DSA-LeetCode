class Solution {
public:
    int minimumDeviation(vector<int>& n) {
    int res = INT_MAX, min_n = INT_MAX;
    for (int i = 0; i < n.size(); ++i) {
        n[i] = n[i] % 2 ? n[i] * 2 : n[i];
        min_n = min(min_n, n[i]);
    }     
    make_heap(begin(n), end(n));
    while (n[0] % 2 == 0) {
        res = min(res, n[0] - min_n);
        min_n = min(min_n, n[0] / 2);
        pop_heap(begin(n), end(n));
        n.back() /= 2;
        push_heap(begin(n), end(n));
    }
    return min(res, n[0] - min_n);
    }
};