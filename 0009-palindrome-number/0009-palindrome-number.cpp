class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
        long long rev = 0;
        while(x>0) {
            int d = x % 10;
            rev = rev*10 + d;
            x/=10;
        }
        return (rev==num) ? true : false;
    }
};