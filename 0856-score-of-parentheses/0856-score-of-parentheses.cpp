class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int res = 0;

        for(char ch : s) {
            if(ch == '(') {
                st.push(res);
                res = 0;
            }
            else {
                res = st.top() + max(res * 2, 1);
                st.pop();
            }
        }

        return res;
    }
};