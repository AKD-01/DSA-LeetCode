class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto mid = nums.begin() + nums.size() / 2;
        ranges::nth_element(nums, mid);
        int med = *mid, moves = 0;
        for (int x : nums) moves += abs(x - med);
        return moves;
    }
};