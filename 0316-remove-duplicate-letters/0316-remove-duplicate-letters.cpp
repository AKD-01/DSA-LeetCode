class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        unordered_map<char, bool> visited;
        stack<int> st;
        string res = "";
        for(char ch:s)	freq[ch]++;
        for(int i = 0; i < n; i++){
            freq[s[i]]--;
            if(visited[s[i]])	continue;
            while(!st.empty() &&  s[i] < s[st.top()] && freq[s[st.top()]] > 0){
                visited[s[st.top()]] = false;
                st.pop();
            }
            st.push(i);
            visited[s[i]] = true;
        }
        while(!st.empty()){
            res = s[st.top()] + res;
            st.pop();
        }
        return res;
    }
};