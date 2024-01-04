class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
    for (int n : nums)
        ++m[n];
    int res = 0;
    for (auto [_, cnt] : m) {
        if (cnt == 1)
            return -1;
        res += cnt / 3 + (cnt % 3 > 0);
    }
    return res;
    }
};