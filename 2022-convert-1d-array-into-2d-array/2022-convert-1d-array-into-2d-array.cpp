class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m, vector<int> (n, 0));
        if(original.size()>m*n || original.size() < m*n) return {};
        
        for(int i = 0; i<original.size(); i++){
            int row = i/n, col = i%n;
            ans[row][col] = original[i];
        }
        return ans;
    }
};