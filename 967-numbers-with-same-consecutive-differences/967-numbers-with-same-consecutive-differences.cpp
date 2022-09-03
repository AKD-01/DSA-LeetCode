class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> cur={1,2,3,4,5,6,7,8,9};
        for(int i=2;i<=n;i++){
            vector<int> helper;
            for(int x: cur) {
                int y=x%10;
                if(y+k<10) helper.push_back(x*10+y+k);
                if(k>0 && y-k>=0) helper.push_back(x*10+y-k);
            }
            cur=helper;
        }
        return cur;
    }
};