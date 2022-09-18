class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int>mp;
        int n=changed.size();
        if(n%2==1)return {};
        for(int i=0;i<n;i++){
            mp[changed[i]]++;
        }
        vector<int>ans;
        sort(changed.begin(),changed.end());
        for(auto x:changed){
        if(mp[x]==0) {
            continue;
        }
        if(mp[x*2]==0) return {};
        ans.push_back(x);
        mp[x]--;
        mp[x*2]--;
        }
        return ans; 
    }
};