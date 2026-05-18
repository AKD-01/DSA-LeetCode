constexpr int N=5e4+1;
bitset<N> vis;
int q[N], front=0, back=0;
class Solution {
public:
    static int minJumps(vector<int>& arr) {
        const int n=arr.size();
        vis.reset();
        unordered_map<int, vector<int>> dict;
        dict.reserve(n);
        for(int i=0; i<n; i++) 
            dict[arr[i]].push_back(i);

        front=back=0;
        q[back++]=0;
        int step=0;
        while(front<back)
        {
            int s=back-front;
            while(s--)
            {
                int cur=q[front++];
                if (cur==n-1) return step;
                if(cur-1>=0 && !vis[cur-1]){
                    q[back++]=cur-1;
                    vis[cur-1]=1;
                }
                if(cur<=n && !vis[cur+1]){
                    q[back++]=cur+1;
                    vis[cur+1]=1;
                }
                for(int idx: dict[arr[cur]]){
                    if (!vis[idx]){
                        q[back++]=idx;
                        vis[idx]=1;
                    }
                }
                dict[arr[cur]].clear();
            }
            step++;
        }
        return -1;
    }
};