class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(3, -1));
        return findEvents(events, 0, 0, dp);
    }
    int findEvents(vector<vector<int>>& events, int idx, int cnt,
                   vector<vector<int>>& dp) {
        if (cnt == 2 || idx >= events.size()) return 0;
        if (dp[idx][cnt] == -1) {
            int end = events[idx][1];
            int lo = idx + 1, hi = events.size() - 1;
            while (lo < hi) {
                int mid = lo + ((hi - lo) >> 1);
                if (events[mid][0] > end)
                    hi = mid;
                else
                    lo = mid + 1;
            }
            int include =
                events[idx][2] + (lo < events.size() && events[lo][0] > end
                                      ? findEvents(events, lo, cnt + 1, dp)
                                      : 0);
            int exclude = findEvents(events, idx + 1, cnt, dp);
            dp[idx][cnt] = max(include, exclude);
        }
        return dp[idx][cnt];
    }
};