class Solution {
public:
        vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
            int m = mat.size(), n =mat[0].size(), row=0, col=0;
            vector<int> result;
            bool up =true;
            while(row<m && col<n){
                if(up){
                    while(row>0&&col<n-1){
                        result.push_back(mat[row][col]);
                        row--;
                        col++;
                    }
                    result.push_back(mat[row][col]);
                    if(col==n-1){
                        row++;
                    }
                    else{
                        col++;
                    }
                }
                else{
                  while(row<m-1&&col>0){
                      result.push_back(mat[row][col]);
                      row++;
                      col--;
                  }
                  result.push_back(mat[row][col]);
                  if(row==m-1){
                      col++;
                  }
                  else{
                      row++;
                  }
                }
                up=!up;
            }        
        return result;
    }
};