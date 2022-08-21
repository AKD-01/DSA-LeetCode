class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = -1;
        for(int i=0; i<sentences.size(); i++) {
            int count=1;
            for(int j=0; j<sentences[i].size(); j++){
                if(sentences[i][j]==' ')count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }  
};