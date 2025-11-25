class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k == 1) return 1;
        int prevRem = 1, rem = 1;
        int len = 1;
        while(len <= k){
            len++;
            int currRem = (10*prevRem)%k;
            rem = (rem + currRem)%k;
            if(rem == 0) return len;
            prevRem = currRem;
        }return -1;
    }
};