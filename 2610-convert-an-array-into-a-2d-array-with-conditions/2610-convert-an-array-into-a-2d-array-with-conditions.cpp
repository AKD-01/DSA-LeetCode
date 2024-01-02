class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& A) {
       int n = A.size();
        vector<int> count(n + 10);
        vector<vector<int>> res;
        for (int a : A) {
            if (res.size() <= count[a])
                res.push_back({});
            res[count[a]++].push_back(a);
        }
        return res; 
    }
};