class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int window_len=0;
        int max_window_len=0;
        unordered_map<char,int> m;
        while(j<s.length()) {
            char ch=s[j];
            //if it is inside the hashmap and its index>=start of the current window
            if(m.count(ch) and m[ch]>=i) {
                i=m[ch]+1;
                window_len=j-i; //updated remaining window len excluding current char
            }
            //update the last occurence
            m[ch]=j;
            window_len++;
            j++;
            //update max_window_len at every step
            if(window_len>max_window_len) {
                max_window_len=window_len;
            }
        }
        return max_window_len;
    }
};