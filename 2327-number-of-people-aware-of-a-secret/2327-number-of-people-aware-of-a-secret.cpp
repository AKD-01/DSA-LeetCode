class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> peopleKnow(n+1, 0);
        int mod = 1e9+7;
        peopleKnow[1] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = i+delay; j <= n && j < i+forget; j++){
                peopleKnow[j] += peopleKnow[i];
                peopleKnow[j] %= mod;
            }
        }
        long long ans = 0;
        for(int i = n-forget+1; i <= n; i++){
            ans += peopleKnow[i];
            ans %= mod;
        }
        return ans;
    }
};