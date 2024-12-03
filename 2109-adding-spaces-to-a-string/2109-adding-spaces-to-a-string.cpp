class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length(), m = spaces.size();
        string ans(m+n, ' ');
        int p = 0, q = 0, idx = 0;
        while(p < n || q < m) {
            if(q < m && p == spaces[q]) { 
                ++idx, 
                ++q; 
            }
            else { ans[idx++] = s[p++]; }
        }
        return ans;
    }
};