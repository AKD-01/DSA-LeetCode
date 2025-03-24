class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int freeDays = 0, lastEnd = 0;

        sort(meetings.begin(), meetings.end());

        for (auto& m : meetings) {
            int start = m[0], end = m[1];

            if (start > lastEnd + 1) {
                freeDays += start - lastEnd - 1;
            }

            lastEnd = max(lastEnd, end);
        }

        return freeDays + (days - lastEnd);
    }
};
