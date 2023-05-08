class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int sum=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==j) sum+=mat[i][i];
                if(i+j==m-1 && i!=j) sum+=mat[i][j];
            } 
        }
        return sum;
    }
};