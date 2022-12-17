class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto s: tokens){
            if(s.size()>1 || isdigit(s[0])) stk.push(stoi(s));
            else {
                auto x2=stk.top(); 
                stk.pop();
                long x1=stk.top();
                stk.pop();
                switch(s[0]) {
                        case '+': x1+=x2;
                        break;
                        case '-': x1-=x2;
                        break;
                        case '*': x1*=x2;
                        break;
                        case '/': x1/=x2;
                        break;
                }
                stk.push(x1);
            }
        }
        return stk.top();
    }
};