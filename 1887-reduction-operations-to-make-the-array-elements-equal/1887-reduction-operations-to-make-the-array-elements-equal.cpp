class Solution {
public:
    int reductionOperations(vector<int>& n) {
       int res = 0, sz = n.size();
       sort(begin(n), end(n));
        for (int j = sz - 1; j > 0; --j)
        if (n[j - 1] != n[j])
            res += sz - j;
        return res; 
    }
};