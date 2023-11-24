class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans=0;
        sort(piles.begin(), piles.end(), greater<int>());
        int len=piles.size()/3;
        for(int i=1;i<piles.size()-len;i+=2){
            ans+=piles[i];
        }
        return ans;
    }
};