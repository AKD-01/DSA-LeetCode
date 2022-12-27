class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         vector<vector<int>> result;
        
        for (size_t i = 0; i < intervals.size(); i++)
        {
			//  the new interval is after the range of other interval, so we can leave the current interval baecause the new one does not overlap with it
            if (intervals[i][1] < newInterval[0])
            {
                result.push_back(intervals[i]);
            }
			// the new interval's range is before the other, so we can add the new interval and update it to the current one
            else if (intervals[i][0] > newInterval[1])
            {
                result.push_back(newInterval);
                newInterval = intervals[i]; 
            }
			// the new interval is in the range of the other interval, we have an overlap, so we must choose the min for start and max for end of interval 
            else if(intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1])
            {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);

            }
        }
        
        result.push_back(newInterval); 
        return result;
    }
};