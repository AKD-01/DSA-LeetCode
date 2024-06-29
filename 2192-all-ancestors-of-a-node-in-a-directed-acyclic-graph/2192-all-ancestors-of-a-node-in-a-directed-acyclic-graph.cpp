class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &curr, vector<bool> &vis)
    {
        vis[node] = true;
        
        for(int nbr : adj[node])
        {
            if(!vis[nbr])
            {
                curr.push_back(nbr);
                
                dfs(nbr, adj, curr, vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int> &edge: edges)
        {
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<vector<int>> answer(n);
        
        for(int i=0; i<n; ++i)
        {
            vector<bool> vis(n, false);
            
            vector<int> curr;
            
            dfs(i, adj, curr, vis);
            
            sort(curr.begin(), curr.end());
            
            answer[i] = curr;
        }
        return answer;
    }
};