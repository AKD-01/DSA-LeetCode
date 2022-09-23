class Solution {
public:
    string reorderSpaces(string text) {
    int cnt = 0;
    string s , res;
    vector<string> v;
    for(char c : text){
        if(c == ' '){
            if(s.size()){
                v.push_back(s);
                s="";
            }
            cnt++;
        }
        else
            s += c;
    }
    if(s.size())
        v.push_back(s);
    int n = v.size() , extraSpaces ,spaces;
    if(n > 1){
        extraSpaces = cnt % (n - 1);
        spaces = cnt/(n - 1);
        for(int i = 0; i < n; i++){
            res += v[i];
            for(int j = 0; j < spaces && i != n - 1; j++)
                res += ' ';
        }
    }
    else{
        extraSpaces = cnt;
        for(int i = 0; i < n; i++)
            res += v[i];
    }
    for(int i = 0; i < extraSpaces; i++)
        res += ' ';
    return res;
    }
};