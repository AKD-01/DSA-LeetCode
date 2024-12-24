class Solution {
private:
      int DFS(int u , int pu , int &maxi , vector<vector<int>> &Graph){
            int H1 = 0 , H2 = 0;
            for(int v : Graph[u]){
                  if(v != pu){
                        int h = DFS(v , u , maxi , Graph);
                        if(h >= H1) H2 = H1 , H1 = h;
                        else if(h > H2) H2 = h;
                  }
            }
            maxi = max(maxi , H1 + H2);
            return 1 + max(H1 , H2);
      }
      int findDiameter(vector<vector<int>> &Edges){
            int n = Edges.size() + 1;
            vector<vector<int>> Graph(n);
            for(vector<int> &E : Edges){
                Graph[E[0]].push_back(E[1]);
                Graph[E[1]].push_back(E[0]);
            } 
            int maxi = 0;
            DFS(0 , -1 , maxi , Graph);
            return maxi;
       }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2){
        int D1 = findDiameter(edges1);
        int D2 = findDiameter(edges2);
        int newDiameter = 1 + (D1 + 1)/2 + (D2 + 1)/2;
        return max({D1 , D2 , newDiameter});
    }
};