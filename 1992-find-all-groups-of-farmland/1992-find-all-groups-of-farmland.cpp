class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
       int m = land.size();
        int n = land[0].size();
        vector<vector<int> >ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(land[i][j]==1 && (j==0 || land[i][j-1]==0) && (i==0 || land[i-1][j]==0)){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    int k=j;
                    while(k<n && land[i][k]==1)
                        k++;
                    k--;
                    int l=i;
                    while(l<m && land[l][j]==1)
                        l++;
                    l--;
                    temp.push_back(l);
                    temp.push_back(k);
                    ans.push_back(temp);
                }
            }
        }
        return ans; 
    }
};