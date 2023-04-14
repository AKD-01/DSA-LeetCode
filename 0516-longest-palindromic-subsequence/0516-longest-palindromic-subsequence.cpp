class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> v0(n), v1(n,1), v(n), *i_2=&v0, *i_1=&v1, *i_=&v;
        for(int i=2;i<=n;i++) {//length
            for(int j=0;j<n-i+1;j++)//start index
                i_->at(j) = s[j]==s[i+j-1]?2+i_2->at(j+1):max(i_1->at(j),i_1->at(j+1));
            swap(i_1,i_2);    
            swap(i_1,i_); //rotate i_2, i_1, i_
        }
        return i_1->at(0); 
    }
};