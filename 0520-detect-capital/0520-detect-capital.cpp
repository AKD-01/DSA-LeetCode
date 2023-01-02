class Solution {
public:
    bool detectCapitalUse(string word) {
        bool firstcap=isupper(word[0]), allcaps=true, allsmall=true;
        for(int i=1;i<word.size();i++) {
            if(isupper(word[i])) allsmall=false;
            else allcaps=false;
        }
        return (firstcap && allcaps) || allsmall;
    }
};