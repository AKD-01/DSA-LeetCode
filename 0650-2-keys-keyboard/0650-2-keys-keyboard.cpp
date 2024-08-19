class Solution {
    pair<int,int> factor(int n){
        pair<int,int> ans;
        for(int i=2;i<=n;i++){
            if(n%i == 0){
                ans = make_pair(i,n/i);
                break;
            }
        }
        return ans;
    }
    bool isPrime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
public:
    int minSteps(int n) {
        if(n==1) return 0;
        if(isPrime(n)) return n;
        vector<int> dp(n+1,-1);
        dp[1] = 0;
        dp[2] = 2;
        dp[3] = 3;
        if(n<=3) return dp[n];

        for(int i=4;i<=n/2;i++){
            if(isPrime(i)){dp[i] = i; continue;}
            auto it = factor(i);
            dp[i] = dp[it.first] + dp[it.second];
        }
        auto it = factor(n);
        return dp[n] = dp[it.first] + dp[it.second];
    }
};