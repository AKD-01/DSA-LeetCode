class Solution {
public:
bool fact(string t,string s){
     for(int i=0;i<s.size();i++){
         if(s[i]!=t[i]){
             return 0;
         }
     }
     return 1;
}
    int isPrefixOfWord(string sentence, string searchWord) {  
        stringstream ss(sentence);
        string q;
         int d=0;
         int n=searchWord.size();
        while(ss>>q){
            d++;
            if(q.size()>=n){
            if(fact(q,searchWord)) return d;
            }
        }
      return -1;   
    }
};