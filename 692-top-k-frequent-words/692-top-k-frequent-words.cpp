class Solution {
static bool cmp(pair<string,int> a, pair<string,int> b){
    if(a.second>b.second)   // greater freq first
        return true;
    else if(a.second==b.second){   // if equal then string lower at top
        return a.first<b.first;
    }
    return false;
}
public: 
    vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string,int>ump;
    for(auto it:words) {
        ump[it]++;
    }
    vector<pair<string,int>>v;
    for(auto it:ump) {
        v.push_back({it.first,it.second});
    }
    sort(v.begin(),v.end(),cmp);
    vector<string>ans;
    for(int i=0;i<k;i++) {
        ans.push_back(v[i].first);
    }
    return ans;
  }
};