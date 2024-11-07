class Solution {
public:
    int largestCombination(vector<int>& A) {
      int res = 0, cur = 0;
        for (int i = 0; i < 30; ++i, cur = 0)
            for (int a: A)
                res = max(res, cur += a >> i & 1);
        return res;    
    }
};