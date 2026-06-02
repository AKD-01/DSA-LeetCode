class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int land = landStartTime[i] + landDuration[i];
                int land_water =
                    max(land, waterStartTime[j]) + waterDuration[j];
                res = min(res, land_water);

                int water = waterStartTime[j] + waterDuration[j];
                int water_land = max(water, landStartTime[i]) + landDuration[i];
                res = min(res, water_land);
            }
        }
        return res;
    }
};