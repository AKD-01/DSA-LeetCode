class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int col = n / rows;
        vector<vector<char>> mat(rows, vector<char>(col));
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                mat[i][j] = encodedText[k++];
            }
        }
        int i = 0, j = 0;
        string s = "";
        while (i < rows && j < col) {
            int prev = j;
            
            while (i < rows && j < col) {
                s += mat[i][j];
                i++;
                j++;
            }
            if (i >= rows || j >= col) {
                i = 0;
                j = prev + 1;
            }
        }
        while (!s.empty() && s.back() == ' ') {
    s.pop_back();
}
        return s;
    }
};