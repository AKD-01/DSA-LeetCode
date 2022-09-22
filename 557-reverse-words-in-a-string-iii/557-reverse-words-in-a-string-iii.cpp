class Solution {
public:
    string reverseWords(string s) {
        int i=0, j=0, n=s.size();
        while(i<n) {
        if(j<n && s[j] != ' ') {
            j++;
        }
        else {
            reverse(s.begin()+i, s.begin()+j);
            i=j+1;
            j=i;
        }
    }
    return s; 
    }
};