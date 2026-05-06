class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(result[i].begin(), result[i].end());
        }

        for (int j = 0; j < m; j++) {
            for (int i = n - 1; i >= 0; i--) {
                if (result[i][j] == '.') {  
                    int nextRowWithStone = -1;

                    for (int k = i - 1; k >= 0; k--) {
                        if (result[k][j] == '*')
                            break;  
                        if (result[k][j] ==
                            '#') {  
                            nextRowWithStone = k;
                            break;
                        }
                    }
                    if (nextRowWithStone != -1) {
                        result[nextRowWithStone][j] = '.';
                        result[i][j] = '#';
                    }
                }
            }
        }
        return result;
    }
};