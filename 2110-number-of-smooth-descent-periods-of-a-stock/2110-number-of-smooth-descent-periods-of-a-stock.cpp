class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long res = 1;
        int prev = 1;  
        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i - 1] - 1) {
                ++prev;
            } else {
                prev = 1;
            }
            res += prev;
        }
        return res;
    }
};