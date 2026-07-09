class Solution {
public:
    vector<int> parent,rnk;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int x,int y){
        int parx=find(x);
        int pary=find(y);
        
        if(rnk[parx]>rnk[pary]) parent[pary]=parx;
        else if(rnk[parx]<rnk[pary]) parent[parx]=pary;
        else{
            parent[pary]=parx;
            rnk[parx]++;
        } 
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
       
        parent.resize(n);
        rnk.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;

        for(int i=1;i<n;i++){
            if(abs(nums[i]-nums[i-1])<=maxDiff) Union(i,i-1); 
        }

        int m=queries.size();
        vector<bool> ans(m);
        for(int i=0;i<m;i++){
            int x=queries[i][0],y=queries[i][1];
            if(find(x)==find(y)) ans[i]=true;
            else ans[i]=false;
        }
        return ans;
    }
};