class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
       int k = nums.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        int maxValue = INT_MIN;
        
        for (int i = 0; i < k; ++i) {
            minHeap.push({nums[i][0], {i, 0}});
            maxValue = max(maxValue, nums[i][0]);
        }

        int rangeStart = 0, rangeEnd = INT_MAX;
        
        while (!minHeap.empty()) {
            auto [minValue, pos] = minHeap.top();
            minHeap.pop();
            int row = pos.first, col = pos.second;
            
            if (maxValue - minValue < rangeEnd - rangeStart) {
                rangeStart = minValue;
                rangeEnd = maxValue;
            }
            
            if (col+1  < nums[row].size()) {
                minHeap.push({nums[row][col + 1], {row, col + 1}});
                maxValue = max(maxValue, nums[row][col + 1]);
            } else {
                break;
            }
        }
        
        return {rangeStart, rangeEnd}; 
    }
};