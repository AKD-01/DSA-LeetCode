class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> x;
    int res = 0;
    for (auto &p : points)
        x.insert(p[0]);
    for (auto it = next(begin(x)); it != end(x); ++it)
        res = max(res, *it - *prev(it));
    return res;
    }
};