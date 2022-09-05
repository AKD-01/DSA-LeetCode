class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++) {
            m[s[i]]++;
        }
        int ans=0;
        bool odd_found=false;
        for(auto val: m){
            if(val.second%2==0) ans+=val.second;
            else {
                odd_found=true;
                ans+=val.second-1;
            }
        }
        if(odd_found) ans++;
        return ans;
    }
};