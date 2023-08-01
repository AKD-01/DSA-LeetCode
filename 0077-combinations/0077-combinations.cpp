class Solution {
public:
     void solve(int n, int k, int num, vector<int> &sub_ans, vector<vector<int>> &ans){
        if(k==0){
            ans.push_back(sub_ans);
            return;
        }
        if(num == n+1) return;
        
        // skip
        solve(n,k,num+1,sub_ans,ans);
        
        // acquire
        sub_ans.push_back(num);
        solve(n,k-1,num+1,sub_ans,ans);
        sub_ans.pop_back();
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> sub_ans;
        solve(n,k,1,sub_ans,ans);
        return ans;
    }
};