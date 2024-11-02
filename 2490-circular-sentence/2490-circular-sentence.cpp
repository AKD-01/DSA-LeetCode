class Solution {
public:
    bool isCircularSentence(string sen) {
    int sz = sen.size();
    if(sen[0] != sen[sz - 1]) return false;
    for(int i = 0; i < sz;++i)
        if(sen[i] == ' ' && sen[i - 1] != sen[i + 1]) return false;
    return true;   
    }
};