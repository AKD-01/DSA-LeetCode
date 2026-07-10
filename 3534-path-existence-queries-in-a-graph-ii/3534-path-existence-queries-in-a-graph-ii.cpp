constexpr int L=18, N=1e5+1;
using int2=pair<int, int>;
int up[L][N], pos[N]; 
int2 xId[N];

class Solution {
public:
    static int cnt(int u, int v, int L) {
        if (u==v) return 0;
        if (up[0][u]>=v) return 1;
        if (up[L-1][u]<v) return -1; 

        int step=0;
        for (int j=L-1; j>=0; j--) { 
            if (up[j][u]<v) { 
                step+=(1<<j);
                u=up[j][u];
            }
        }
        return step+1;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int maxL=bit_width((unsigned)n)+1;
        for(int i=0; i<n; i++) 
            xId[i]={nums[i], i};
        
        sort(xId, xId+n);
        for (int i=0; i<n; i++)
            pos[xId[i].second]=i;
        
        for (int l=0, r=0; l<n; l++) {
            while (r+1<n && xId[r+1].first-xId[l].first<=maxDiff) 
                r++;
            up[0][l]=r;
        }

        for (int j=1; j<maxL; j++) {
            for (int i=0; i<n; i++) {
                up[j][i]=up[j-1][up[j-1][i]];
            }
        }

        const int qz=queries.size();
        vector<int> ans(qz);
        int i=0;
        for (auto& q : queries) {
            auto [u, v]=minmax(pos[q[0]], pos[q[1]]);
            ans[i++]=cnt(u, v, maxL);
        }
        return ans;
    }
};