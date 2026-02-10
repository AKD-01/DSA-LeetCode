class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        size_t len = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            auto odd = unordered_map<int, int>();
            auto even = unordered_map<int, int>();

            for (size_t j = i; j < nums.size(); j++) {
                auto& c = (nums[j] & 1) ? odd : even;
                c[nums[j]]++;

                if (odd.size() == even.size()) {
                    len = std::max(len, j - i + 1);
                }
            }
        }

        return int(len);
    }
};