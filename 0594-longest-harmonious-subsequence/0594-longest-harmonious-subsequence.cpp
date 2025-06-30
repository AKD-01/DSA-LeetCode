class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;

        for (int num : nums) {
            ++frequencyMap[num];
        }

        int longestHarmoniousSequence = 0;

        for (auto& [num, count] : frequencyMap) {
            if (frequencyMap.count(num + 1)) {
                longestHarmoniousSequence = max(longestHarmoniousSequence, count + frequencyMap[num + 1]);
            }
        }

        return longestHarmoniousSequence;

    }
};