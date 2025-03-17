class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int maxVal = 0;
        for (int num : nums) maxVal = max(num, maxVal);

        vector<bool> paired(maxVal + 1, false);
        for (int num : nums) paired[num] = !paired[num];

        for (int num : nums) if (paired[num]) return false;

        return true;
    }
};
