//reflection*q=extension*p
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int ref=p, ext=q;
        
        while(ref%2==0 && ext%2==0){
            ext/=2;
            ref/=2;
        }
        
        if(ref%2!=0 && ext%2==0) return 0;
        if(ref%2!=0 && ext%2==1) return 1;
        if(ref%2==0 && ext%2==1) return 2;
        
        return -1;
    }
};