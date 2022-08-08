class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minimum=INT_MAX;
       int maximum_profit=0;
        for(int i=0;i<prices.size();i++)
        {
            minimum=min(minimum,prices[i]);
            maximum_profit=max(maximum_profit,prices[i]-minimum);
        }
        return maximum_profit;
     }
};

//Time Complexity = O(n);
//Space Complexity = O(1);