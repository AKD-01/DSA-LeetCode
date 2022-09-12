class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int maxpoints=0, points=0, i=0, j=tokens.size()-1;
        while(i<=j) {
            if(power>=tokens[i]) {
                points++;
                power-=tokens[i++];
                maxpoints=max(maxpoints,points);
            }
            else if(points>0) {
                points--;
                power+=tokens[j--];
            }
            else {
                return maxpoints;
            }
        }
        return maxpoints;
    }
};