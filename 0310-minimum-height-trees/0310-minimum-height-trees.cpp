class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)
            return {};
        if(n==1)
            return {0};
        vector<int>res;
        vector<int>degrees(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degrees[edges[i][1]]++;
            degrees[edges[i][0]]++;
        }
        queue<int>queue;
        for(int i=0;i<n;i++)
        {
            if(degrees[i]==1)
                queue.push(i);
        }
        while(!queue.empty())
        {
            res.clear();
            int size=queue.size();
            for(int i=0;i<size;i++)
            {
                int cur=queue.front();
                queue.pop();
                res.push_back(cur);
                for(auto &neighbor:adj[cur])
                {
                    degrees[neighbor]--;
                    if(degrees[neighbor]==1)
                        queue.push(neighbor);
                }
            }
        }
        return res;
    }
};