class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans(queries.size());
        vector<pair<int ,int>> queriesPair;
        
        for (int i = 0; i < queries.size(); i++) {
            queriesPair.push_back({queries[i], i});
        }
        
        sort(queriesPair.begin(), queriesPair.end());
        sort(items.begin(), items.end());
        
        int itemIndex = 0, maxBeauty = 0;
        for (int i = 0; i < queriesPair.size(); i++) {
            int maxPriceAllowed = queriesPair[i].first;
            int queryOriginalIndex = queriesPair[i].second;
            
            // Iterate over items, stop when the price exceeds query price or no item left
            while (itemIndex < items.size() && items[itemIndex][0] <= maxPriceAllowed) {
                maxBeauty = max(maxBeauty, items[itemIndex][1]);
                itemIndex++;
            }
            
            ans[queryOriginalIndex] = maxBeauty;
        }
        
        return ans;
    }
};