class Solution {
public:
    int canBeTypedWords(string& text, string& brokenLetters) {
        unsigned mask=0;
        for(char c: brokenLetters)
            mask|=(1<<(c-'a'));
        int cnt=0;
        bool word=1;
        text.push_back(' ');
        for(char c: text){
            if (c==' '){
                cnt+=word;
                word=1;
            }
            else if (mask &(1<<(c-'a'))) word=0;  
        }
        return cnt;
    }
};