class Solution {
public:
    int dp[310][10010];
    int func(int index,int amount,vector<int>& coins){
        if(amount==0) return 1;
        if(index<0) return 0;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int ways=0;
        for(int coin_amount=0;coin_amount<=amount;coin_amount+=coins[index]){
            ways+=func(index-1,amount-coin_amount,coins);
        }
        return dp[index][amount]=ways;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return func(coins.size()-1,amount,coins);
    }
};