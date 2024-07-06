class Solution {
public:
    int passThePillow(int n, int time) {
        int x = time/(n-1);
        time %= (n-1);
        if(!(x&1)){
            return 1+time;
        }
        return n-time; 
    }
};