class Solution {
public:
    bool isSubsequence(string s, string t) {
       int i=s.size(), j=t.size();
       while(i>=0 and j>=0) {
           if(i==0 and s[i]==t[j]) {
               return true;
           }
           else if(s[i]==t[j]) {
               i--;
               j--;
           }
           else if(s[i]!=t[j]) {
               j--;
           }
       }
        return false;
    }
};