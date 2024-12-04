class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
      int n = str1.size(), m = str2.size();
        int i = 0,j = 0;
        while (i < n and j < m) {
            if (str1[i] == str2[j]) {
                i++, j++;
            } else {
                if (str1[i] =='z') str1[i]='a';
                 else  str1[i]++;
                if (str1[i] == str2[j]) {
                    i++, j++;
                } else {
                    if (str1[i] == 'a') str1[i] = 'z';
                    else str1[i]--;
                    i++;
                }
            }
        }
        return j==m;  
    }
};