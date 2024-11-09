class Solution {
public:
    long long minEnd(int n, int x) {
        long long a = x;
        while (--n) {
            a = (a + 1) | x; 
        }
        return a;
    }
};