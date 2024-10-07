class Solution {
public:
    int minLength(string s) {
      stack<char>st;
        for(auto x:s) {
            if(!st.empty() and ((x=='B' and st.top()=='A') || (x=='D' and  st.top()=='C')))
                st.pop();
            else
                st.push(x);           
        }
        return st.size();  
    }
};