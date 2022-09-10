class Solution {
public:
    int f[31];
    int fib(int n) {
        if(n==0 || n==1) return n;
        f[0]=0;
        f[1]=1;
        for(int i=2; i<=n;i++){
            f[i]=f[i-1]+f[i-2];
        }
        return f[n]; 
    }
};