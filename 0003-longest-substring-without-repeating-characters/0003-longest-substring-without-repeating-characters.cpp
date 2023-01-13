class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        if(str.size()==0) return 0;
        int ans=INT_MIN;
        unordered_set<char> s;
        int l=0;
        for(int r=0; r<str.length(); r++) {
            if(s.find(str[r]) != s.end()) {
                while(l<r && s.find(str[r]) != s.end()) {
                    s.erase(str[l]);
                    l++;
                }
            }
            s.insert(str[r]);
            ans=max(ans, r-l+1);
        }
        return ans;
    }
};