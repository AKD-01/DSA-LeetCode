class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int,int>m;
        int n = tops.size();
        int mina = INT_MAX;
        for(int i=0;i<n;i++){
            m[tops[i]]++;
            m[bottoms[i]]++;
        }
        for(auto i:m){
            int topcount = 0;
            int bottomcount = 0;
            bool flag = true;
            if(i.second >= n){
                for(int j=0;j<n;j++){
                    if(tops[j] != i.first && bottoms[j] != i.first){
                        flag = false;
                        break;
                    }
                    if(tops[j] == bottoms[j] && tops[j] == i.first);
                    else if(tops[j] == i.first)topcount++;
                    else bottomcount++;
                }
                if(flag){
                    mina = min(mina,min(topcount,bottomcount));
                }
            }
        }
        return mina == INT_MAX ? -1: mina;
    }
};