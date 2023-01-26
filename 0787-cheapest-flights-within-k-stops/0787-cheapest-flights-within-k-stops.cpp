class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int sink, int k) {
        vector<int> c(n, 1e8);
        c[src] = 0;
        for(int z=0; z<=k; z++){
            vector<int> C(c);
            for(auto e: a)
                C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
            c = C;
        }
        return c[sink] == 1e8 ? -1 : c[sink];
    }
};