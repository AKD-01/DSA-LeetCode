class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        for (int i = 0; i < prices.size(); i++){
            bool flag = false;
            for (int j = i + 1; j < prices.size(); j++){
                if (prices[i] >= prices[j]){ 
                    int temp = prices[i] - prices[j];  
                    ans.push_back(temp);
                    flag = true; 
                    break;
                }
            }

            if (!flag){ 
                ans.push_back(prices[i]);
            }
        }
        return ans; 
    }
};