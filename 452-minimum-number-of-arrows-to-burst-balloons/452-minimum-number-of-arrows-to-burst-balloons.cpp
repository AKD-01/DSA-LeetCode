class Solution {
public:
    static bool cmp(vector<int> &point_1, vector<int> &point_2) {
        if(point_1[1]==point_2[1]) {
            return point_1[0]<point_2[0];
        }
        return point_1[1]<point_2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int lastpointshot=points[0][1];
        int shotfired=1;
        for(auto point:points) {
            if(point[0]>lastpointshot) {
                shotfired++;
                lastpointshot=point[1];
            }
        }
        return shotfired;
    }
};