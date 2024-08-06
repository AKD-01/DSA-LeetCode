class Solution {
public:
    int minimumPushes(string word) {
       vector<int> freq(26,0);
        int n=word.size(),count=0,ans=0;
        for(int i=0;i<n;i++){
            freq[word[i]-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        for(int i=0;i<26;i++){
            if(freq[i]==0) break;
            if(count<=7){
                ans+=freq[i];
            }
            else if(count<=15){
                ans+=freq[i]*2;
            }
            else if(count<=23){
                ans+=freq[i]*3;
            }
            else{
                ans+=freq[i]*4;
            }
            count++;
        }
        return ans; 
    }
};