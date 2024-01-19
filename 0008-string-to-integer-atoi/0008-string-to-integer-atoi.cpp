class Solution {
public:
    int myAtoi(string s) {
        long long int res=0;
        bool b=false;//true -ve,  false +ve;
        int i=0,num;
        while(s[i]==' ') i++;
        if(s[i]=='+' || s[i] =='-' || (s[i]>='0' && s[i]<='9')){}
        else return 0;
        if(s[i]=='+') i++; else if(s[i]=='-'){b= true; i++;}
        while(s[i]>='0' && s[i]<='9') {
            num=(int) s[i] -48; i++;
            res= (res*10)+num;
            if(res>INT_MAX && res>0 )
            {if(b) return INT_MIN;  else return INT_MAX;}
        }
        if(b){res*=-1;}
        return res;
    }
};