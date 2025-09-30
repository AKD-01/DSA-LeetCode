static array<int, 10> inv{};
class Solution {
public:
    //(exponent 2, exponent 5, factor coprime to 2, 5 mod 10)
    using int3=array<int, 3>; 
    static void inv_mod10(){
        if (inv[1]==1) return;
        inv[1]=1, inv[3]=7, inv[7]=3, inv[9]=9;
    }
    static int3 factor(unsigned x){
        int exp2=countr_zero(x);
        x>>=exp2;
        int exp5=0;
        for (;x%5==0; x/=5) exp5++;
        x%=10;
        return {exp2, exp5, int(x)};
    }
    static int3 mul(const int3& x, const int3& y){
        return {x[0]+y[0], x[1]+y[1], x[2]*y[2]%10};
    }
    static int3 div(const int3& x, const int3& y){
        return {x[0]-y[0], x[1]-y[1], x[2]*inv[y[2]]%10};
    }
    static int Pow(int b, int exp){
        if(exp==0) return 1;
        int y=(exp&1)?b:1;
        return Pow(b*b, exp>>1)*y;
    }
    static int toInt(const int3& x){
        return (Pow(5, x[1])<<x[0])*x[2]%10;
    }
    static vector<int> Comb(int n){
        vector<int3> a(n+1, {0, 0, 0});
        vector<int> A(n+1);
        a[0]=a[n]={0, 0, 1};
        A[0]=A[n]=1;
        for(int k=1; k<=n/2; k++){
            a[k]=a[n-k]=div(mul(a[k-1], factor(n-k+1)), factor(k));
            A[k]=A[n-k]=toInt(a[k]);
        }
        return  A;
    }
    static int triangularSum(vector<int>& nums) {
        const int n=nums.size()-1;
        inv_mod10();
        auto A=Comb(n);
        int ans=0;
        for(int i=0; i<=n; i++){
            ans=(ans+A[i]*nums[i])%10;
        }
        return ans;
    }
};