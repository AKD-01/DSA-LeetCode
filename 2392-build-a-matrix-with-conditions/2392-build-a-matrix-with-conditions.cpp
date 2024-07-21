class Solution {
public:
    vector<int> kahn(vector<vector<int>> &matrix,int k){
    vector<int> indegree(k+1,0);
    vector<int> adj[k+1];
    queue<int> q;
    vector<int> res;
    for(auto x:matrix){
        adj[x[0]].push_back(x[1]);
        indegree[x[1]]++;
        
    }
    for(int i=1;i<=k;i++){
        if(indegree[i]==0){
            q.push(i);    
        }
    }
    while(!q.empty()){
        int aux=q.front();
        q.pop();
        res.push_back(aux);
        for(auto out:adj[aux]){
            indegree[out]--;
            if(indegree[out]==0){
                q.push(out);
            }
        }
    }
    return res;   
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<vector<int>> res(k,vector<int>(k,0));
    vector<int> ans1=kahn(rowConditions,k);
    vector<int> ans2=kahn(colConditions,k);
    if(ans1.size()!=k)return {};
    if(ans2.size()!=k) return {};
    for(int i=1;i<=k;i++){
        int r=find(ans1.begin(),ans1.end(),i)-ans1.begin();
        int c=find(ans2.begin(),ans2.end(),i)-ans2.begin();
        res[r][c]=i;
    } 
    return res;
}
};