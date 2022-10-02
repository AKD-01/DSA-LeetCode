class Solution {
public:
    bool isSubsequence(string s, string t) {
       int i=s.size()-1, j=t.size()-1;
       while(i>=0 and j>=0) {
           if(t[j]==s[i]) {
               j--;
               i--;
           }
           else {
               j--;
           }
       }
        if(i==-1) return true;
        return false;
    }
};