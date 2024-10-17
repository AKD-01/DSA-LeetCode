class Solution {
public:
    int maximumSwap(int num) {
       string s = to_string(num);
        int n=s.size();
        int max_ind=n-1,j=n-1;
        int ans=num;
        while(j>=0){
            int x= s[j]-'0';
            int maxi=s[max_ind]-'0';
            if(j!=max_ind && x<=maxi){
               swap(s[j],s[max_ind]);
               ans=max(ans,stoi(s));
               swap(s[j],s[max_ind]);
            }
            else {
              max_ind=j;
            }
            j--;
        
        }
        return ans; 
    }
};