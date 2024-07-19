class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
       vector<int> res;
        unordered_set<int> s;
        for(int i = 0; i < matrix.size(); ++i){
            int mn = INT_MAX; 
            for(int j = 0; j < matrix[0].size(); ++j)  mn = min(mn, matrix[i][j]);
            s.insert(mn);
        }    
        for(int j = 0; j < matrix[0].size(); ++j){
            int mx = INT_MIN;
            for(int i = 0; i < matrix.size(); ++i) mx = max(mx, matrix[i][j]); 
            if(s.find(mx)!=s.end()) res.push_back(mx);
        }
        return res; 
    }
};