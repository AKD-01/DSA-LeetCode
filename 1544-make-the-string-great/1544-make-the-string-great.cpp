class Solution {
public:
    string makeGood(string s) {
        int size = 0;
        while(size != s.size()) {
            size = s.size();
            for(int i = 1; i < s.size(); i++) {
                if(abs(s[i-1]-s[i]) == 32) {
                s.erase(s.begin()+i-1,s.begin()+i+1);
                }
            }
        }
        return s;
    }
};