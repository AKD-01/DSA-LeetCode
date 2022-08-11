class Solution {
public:
    int countSubstrings(string s) {
       vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
       int count=0;
        for(int diff=0;diff<s.size();diff++){
            for(int i=0, j=diff;j<s.size();i++,j++){
                if(diff==0) dp[i][j]=true;
                else if(diff==1) {
                    if(s[i]==s[j]) dp[i][j]=true;
                    else dp[i][j]=false;
                }
                else {
                    if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                    else dp[i][j]=false;
                }
                if(dp[i][j]) count++;
            }  
        }
        return count;
    }
};