class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
         vector<int> cur = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 2; i <= n; ++i) {
            vector<int> cur2;
            for (int x : cur) {
                int y = x % 10;
                if (y + k < 10)
                    cur2.push_back(x * 10 + y + k);
                if (k > 0 && y - k >= 0)
                    cur2.push_back(x * 10 + y - k);
            }
            cur = cur2;
        }
        return cur;
    }
};