class Solution {
public:
    string reverseParentheses(string s) {
      deque<string> st;
        string cur = "";
        for(int i=0;i<s.size();++i){
            if(s[i] == '('){
                st.push_back(cur);
                cur = "";
            }
            else if(s[i] == ')'){
                reverse(cur.begin(),cur.end());
                cur = st.back()+cur;
                st.pop_back();
            }else cur += s[i];
        }
        return cur;  
    }
};