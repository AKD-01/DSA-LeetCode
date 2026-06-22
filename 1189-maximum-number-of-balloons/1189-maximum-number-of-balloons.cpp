class Solution {
public:
    static int maxNumberOfBalloons(string& text) {
        int freq[26]={0};
        for(char c : text){
            freq[c-'a']++;
        }
        return min({freq[0], freq[1], freq['l'-'a']>>1, freq['o'-'a']>>1, freq['n'-'a']});
    }
};