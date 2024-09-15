class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<int,int>m;
        m[0]=-1;
        string v="aeiou";
        int mask=0;
        int res=0;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<5;j++){
                if(s[i]==v[j]){
                    mask=mask^(1<<j);
                    break;
                }
            }
                if(m.find(mask)==m.end()){
                    m[mask]=i;
                }
                res=max(res,i-m[mask]);
            
        }
        return res; 
    }
};