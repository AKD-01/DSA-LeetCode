class Solution {
public:
    int minCostClimbingStairs(vector<int>& C) {
      int n=C.size();
        int dp1=0,dp2=0;
        for(int i=n-1;i>=0;i--) {
            int dpi=C[i]+min(dp1,dp2);
            dp2=dp1;
            dp1=dpi;
        }
        return min(dp1,dp2);
    }
};

/* 
TOP DOWN APPROACH:
int dp[1001];
    int help(int i, vector<int>&C) {
        if(i>=C.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int op1=help(i+1,C);
        int op2=help(i+2,C);
        return dp[i]=min(op1,op2)+C[i];
    }
    int minCostClimbingStairs(vector<int>& C) {
        memset(dp,-1,sizeof dp);
       return min(help(0,C),help(1,C)); 
    }
*/