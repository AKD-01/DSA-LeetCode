class Solution {
private:
    vector<string> sol;
    void backtrack(string &temp, int open, int close) {
        if(open == 0 && close == 0){
            sol.push_back(temp);
            return;
        }
        if(open > 0){
            temp.push_back('(');
            backtrack(temp, open - 1, close);
            temp.pop_back();
        }
        if(close > open){
            temp.push_back(')');
            backtrack(temp, open, close - 1);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        backtrack(str, n, n);
        return sol;
    }
};