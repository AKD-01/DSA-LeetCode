class Solution {
public:
    bool checkBit(int &flag, int &n){
        return flag & (1<<n);
    }
    void setBit(int &flag, int &n){
        flag = flag | (1<<n);
    }
    int partitionString(string s) {
        int flag = 0;
        int i = 0, ans = 1;
        while(i < s.size()){
            int n = s[i] - 'a';
            if( checkBit(flag, n) ) {
                flag = 0;
                ans++;
            }
            setBit(flag, n);
            i++;
        }
        return ans;  
    }
};