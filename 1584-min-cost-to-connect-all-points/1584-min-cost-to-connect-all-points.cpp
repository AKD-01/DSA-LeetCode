class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n=p.size();
        vector<int> dis(n,1e9),vis(n);
        int ans=0;
        dis[0]=0;
        vis[0]=1;
        int k=n-1;
        int j=0;
        while(k--){
            int mini=1e9,mini_i;
            for(int i=0;i<n;i++){
                dis[i]=min(dis[i],abs(p[j][0]-p[i][0])+abs(p[j][1]-p[i][1]));
                if(!vis[i] && mini>dis[i]){
                    mini=dis[i];
                    mini_i=i;
                }
            }
            vis[mini_i]=1;
            ans+=dis[mini_i];
            j=mini_i;
        }
        return ans;
    }
};