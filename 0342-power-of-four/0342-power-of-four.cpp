class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n>1) {
           if(n%4) return false;
            n/=4;
        }
        return n==1;
    }
};