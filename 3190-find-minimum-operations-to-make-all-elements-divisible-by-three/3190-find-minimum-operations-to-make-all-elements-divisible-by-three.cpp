class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0, [](int acc, int v) {
            return acc + std::min(v % 3, 3 - v % 3);
        });
    }
};