class Solution {
public:
    void helper(int i, string &digits, vector<string> &ans, string &temp, unordered_map<char,string> &m) {
        if(digits.size()==0) return;
        if(i==digits.size()) {
            ans.push_back(temp);
            return;
        }
        string str = m[digits[i]];
        for(int j=0; j<str.size(); j++) {
            temp.push_back(str[j]);
            helper(i+1,digits,ans,temp,m);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        vector<string> ans;
        string temp;
        helper(0,digits,ans,temp,m);
        return ans;
    }
};