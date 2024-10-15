class Solution {
public:
    long long minimumSteps(string s) {
        long long int zero = 0, ans = 0; 
        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] == '1') {
                ans += zero; 
            } 
            else {
                zero++; 
            }
        }
        return ans; 
    }
};