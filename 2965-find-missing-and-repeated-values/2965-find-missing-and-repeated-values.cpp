class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       long long sum = 0, sqrSum = 0, n = grid.size(), total = n * n;

        for (auto& row : grid) {
            for (int num : row) {
                sum += num;
                sqrSum += (long long)num * num;
            }
        }

        long long sumDiff = sum - total * (total + 1) / 2;
        long long sqrDiff = sqrSum - total * (total + 1) * (2 * total + 1) / 6;

        int repeat = (sqrDiff / sumDiff + sumDiff) / 2;
        int missing = repeat - sumDiff;

        return {repeat, missing};   
    }
};