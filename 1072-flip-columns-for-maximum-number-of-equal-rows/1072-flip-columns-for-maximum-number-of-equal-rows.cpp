class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
      unordered_map<string,int> hmap;
        for(auto x: matrix){
            string s=""; 
            int top=x[0];
            for(int i=0;i<x.size();i++){
                if(x[i]==top)
                    s+='1';
                else
                    s+='0';
            }
            hmap[s]++; 
        }
        
        int result=0;
        for(auto &[key,val]:hmap)
            result=max(result,val); 
        return result;  
    }
};