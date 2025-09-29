class Solution {
public:
    static int minScoreTriangulation(vector<int>& v) {
        const int n=v.size();
        if (n==3) return v[0]*v[1]*v[2];

        vector<vector<int>> dp(n-1, vector<int>(n, 0));

        for (int d=2; d<=n-1; d++){
            for(int i=0; i<n-d; i++){
                const int j=i+d;
                int w=INT_MAX, e=v[i]*v[j];
                for(int k=i+1; k<j; k++)
                    w=min(w, e*v[k]+dp[i][k]+dp[k][j]);
                dp[i][j]=w;
            } 
        }
        return dp[0][n-1];
    }
};