class Solution {
static bool cmp(vector<int>& point_1, vector<int>& point_2) {
	if(point_1[1] == point_2[1])
		return point_1[0] < point_2[0];
	return point_1[1] < point_2[1];
}
public:
    int findMinArrowShots(vector<vector<int>>& points) {

	sort(points.begin(), points.end(), cmp); // sort points, with points having small endpoint comes first

	int last_point_where_we_shot_an_arrow = points[0][1]; // we shoot an arrow at the smallest endpoint.
	int shots_fired = 1;
	for(auto& point : points) {
		if(point[0] > last_point_where_we_shot_an_arrow) { // if this segment doesn't pass through the last point where we shot an arrow, pick this segment and shoot an arrow at its endpoint
			shots_fired++;
			last_point_where_we_shot_an_arrow = point[1];
		}
	}
	return shots_fired;
    }
};
