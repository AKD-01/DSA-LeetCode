class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto m = max_element(heights.begin(), heights.end());
        vector<int> expected(*m + 1);
        for (int height : heights)
            expected[height]++;
        int res = 0;
        for (int j = 1, i = 0; j < expected.size(); j++)
            while (expected[j]--)
                res += (heights[i++] != j);
        return res;
    }
};