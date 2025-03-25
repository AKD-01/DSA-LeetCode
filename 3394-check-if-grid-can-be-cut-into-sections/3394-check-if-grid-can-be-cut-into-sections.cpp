class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rects) {
        return checkCuts(rects, 0) || checkCuts(rects, 1);
    }

private:
    bool checkCuts(vector<vector<int>>& rects, int dim) {
        int gaps = 0;

        sort(rects.begin(), rects.end(), [dim](const vector<int>& a, const vector<int>& b) {
            return a[dim] < b[dim];
        });

        int maxEnd = rects[0][dim + 2];

        for (size_t i = 1; i < rects.size(); i++) {
            if (maxEnd <= rects[i][dim]) {
                gaps++;
            }
            maxEnd = max(maxEnd, rects[i][dim + 2]);
        }

        return gaps >= 2;
    }
};
