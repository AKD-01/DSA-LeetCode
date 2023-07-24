class Solution {
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        if(target==0) {
            ans.push_back(ds);
            return;
        } 
        for(int i=ind; i<arr.size(); i++) {
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            findCombination(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target,candidates,ans,ds);
        return ans;
    }
};

 //Solution giving TLE
 // void findCombination(int ind, int target, vector<int> &arr, vector<int> &ds, set<vector<int>> &s) {
 //        if(ind==arr.size()) {
 //            if(target==0) s.insert(ds);
 //            return;
 //        }
 //        //To pick up an element
 //        if(arr[ind]<=target) {
 //            ds.push_back(arr[ind]);
 //            findCombination(ind+1, target-arr[ind], arr, ds, s);
 //            ds.pop_back();
 //        }
 //        //Not pick up an element
 //        findCombination(ind+1,target, arr, ds, s);
 //    }
 //    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
 //        sort(candidates.begin(),candidates.end());
 //        set<vector<int>> s;
 //        vector<int> ds;
 //        findCombination(0,target,candidates,ds,s);
 //        vector<vector<int>> ans;
 //        for(auto it: s) {
 //            ans.push_back(it);
 //        }
 //        return ans;
 //    }