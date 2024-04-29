class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int a : nums)
            k ^= a;
        return __builtin_popcount(k);
    }
};