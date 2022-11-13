class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size();
        int start=0, end=0;
        int i=0;
        while(i<n) {
            while(i<n && s[i]!=' ') {
                s[end++]=s[i++];
            }
            if(start<end) {
                reverse(s.begin()+start, s.begin()+end);
                if(end==n) break;
                s[end++]=' ';
                start=end;
            }
            i++;
        }
        if(end>0 && s[end-1]==' ') s.resize(end-1);
        else s.resize(end);
        return s;
    }
};