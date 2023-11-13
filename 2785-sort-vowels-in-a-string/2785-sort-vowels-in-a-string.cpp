class Solution {
public:
    bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'o'|| ch == 'u'|| ch == 'i';
}
string sortVowels(string s) {
    string v;
    copy_if(begin(s), end(s), back_inserter(v), [&](char ch){ 
        return isVowel(tolower(ch)); 
    });
    sort(begin(v), end(v));
    for (int i = 0, j = 0; i < s.size(); ++i)
        if (isVowel(tolower(s[i])))
            s[i] = v[j++];
    return s;
}
};