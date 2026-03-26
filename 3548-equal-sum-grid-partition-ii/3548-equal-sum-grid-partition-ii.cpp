class Solution {
public:
    bool canPartitionGrid(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        
        long long sum = 0;
        unordered_multiset<long long> mst;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                sum += grid[i][j];
                mst.insert(grid[i][j]);
            }
        }
        
        long long currSum = 0, tmpSum = sum;
        unordered_multiset<long long> currMst, tmpMst = mst;
        if(n > 1) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    currSum += grid[i][j];
                    tmpSum -= grid[i][j];
                    currMst.insert(grid[i][j]);
                    tmpMst.erase(tmpMst.find(grid[i][j]));
                }
                
                if(currSum == tmpSum) return true;
                
                if(currSum < tmpSum) {
                    long long diff = tmpSum - currSum;
                    if(tmpMst.find(diff) != tmpMst.end()) {
                        if(m == 1) {
                            if((i + 1 < n && grid[i + 1][0] == diff) || grid[n - 1][0]) return true;
                            continue;
                        }
                        
                        if(tmpMst.size() > m) return true;
                        if(grid[n - 1][0] == diff || grid[n - 1][m - 1] == diff) return true;
                    }
                } else {
                    long long diff = currSum - tmpSum;
                    if(currMst.find(diff) != currMst.end()) {
                        if(m == 1) {
                            if(grid[0][0] == diff || grid[i][0] == diff) return true;
                            continue;
                        }
                        
                        if(currMst.size() > m) return true;
                        if(grid[0][0] == diff || grid[0][m - 1] == diff) return true;                  
                    }
                }
            }
        }
        
        currSum = 0, tmpSum = sum;
        currMst.clear(), tmpMst = mst;
        if(m > 1) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    currSum += grid[j][i];
                    tmpSum -= grid[j][i];
                    currMst.insert(grid[j][i]);
                    tmpMst.erase(tmpMst.find(grid[j][i]));
                }
                
                if(currSum == tmpSum) return true;
                
                if(currSum < tmpSum) {
                    long long diff = tmpSum - currSum;
                    if(tmpMst.find(diff) != tmpMst.end()) {
                        if(n == 1) {
                            if((i + 1 < m && grid[0][i + 1] == diff) || grid[0][m - 1] == diff) return true;
                            continue;
                        }
                        
                        if(tmpMst.size() > n) return true;
                        if(grid[0][m - 1] == diff || grid[n - 1][m - 1] == diff) return true;                    
                    }
                } else {
                    long long diff = currSum - tmpSum;
                    if(currMst.find(diff) != currMst.end()) {
                        if(n == 1) {
                            if(grid[0][0] == diff || grid[0][i] == diff) return true;
                            continue;
                        }
                        
                        if(currMst.size() > n) return true;
                        if(grid[0][0] == diff || grid[n - 1][0] == diff) return true;   
                    }
                }
            }
        }
        
        return false;
    }
};