class Solution {
public:
    int getLucky(string s, int k) {
      string chartonum="";
        int ans=0;
        for(int i=0; i<s.size(); i++){
            int num = s[i]-'a'+1;
            string mid = to_string(num);
            chartonum+=mid;
        }
        while(k)
        {
            ans=0;
            for(int i=0; i<chartonum.size(); i++){
            int ig= chartonum[i]-'0';
            ans+=ig;
        }
         chartonum=to_string(ans);
         k--;
        }
        
        return ans;  
    }
};