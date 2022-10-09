class Solution {
public:
    string minWindow(string s, string t) {
        //array as a freq map or can use hashmap
        int FT[256]={0};
        int FS[256]={0};
        for(int i=0;i<t.length();i++) {
            FT[t[i]]++;
        }
        //Sliding Window Algorithm
        int cnt=0;
        int start=0; //left contraction
        int start_idx=-1; //start_idx for best window
        int min_so_far=INT_MAX; //large number
        int window_size;
        
        for(int i=0; i<s.length(); i++) {
            //expand the window by including current char
            char ch=s[i];
            FS[ch]++;
        
            //count how many characters have been matched till now, s and t.
            if(FT[ch]!=0 and FS[ch]<=FT[ch]) {
                cnt++;
            }
            
            //Another thing if all the characters of the t are found in the current window then start contracting.
            if(cnt==t.length()) {
                //start contracting from left to remove unwanted characters.
                while(FT[s[start]]==0 or FS[s[start]]>FT[s[start]]) {
                    FS[s[start]]--;
                    start++;
                }
                //Note the window size
                window_size=i-start+1;
                if(window_size<min_so_far){
                    min_so_far=window_size;
                    start_idx=start;
                }
            }
        }
        if(start_idx==-1) {
            return {};
        }
        return s.substr(start_idx,min_so_far);
    }
};