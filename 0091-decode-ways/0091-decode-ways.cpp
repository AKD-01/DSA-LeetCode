class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(105);
        dp[0]=1;
        dp[1]=(s[0]=='0')? 0:1;
        
        for(int i=2; i<=n; i++) {
            int d=s[i-1]-'0';
            int dd=10*(s[i-2]-'0')+(s[i-1]-'0');
            
            if(d>=1) dp[i]+=dp[i-1];
            if(dd>=10 && dd<=26) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};