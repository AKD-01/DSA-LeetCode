class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX, maxi=0;
        for(int i=0;i<prices.size();i++) {
            mini=min(mini,prices[i]);
            maxi=max(maxi,prices[i]-mini);
        }
        return maxi;
    }
};