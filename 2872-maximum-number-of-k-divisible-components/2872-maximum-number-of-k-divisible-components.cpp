class Solution {
public:
    int ans=0;
    vector<vector<int>>adj;
    long long int post(int node,int par,int k,vector<int>&val)
    {
        long long int sum=0;
        for(auto it:adj[node])
        {
            if(it==par)continue;
            sum+=post(it,node,k,val);
        }
        sum+=val[node];
        if(sum%k==0)ans++;
        
        return sum%k;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.resize(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        post(0,-1,k,values);
        return ans;
    }
};