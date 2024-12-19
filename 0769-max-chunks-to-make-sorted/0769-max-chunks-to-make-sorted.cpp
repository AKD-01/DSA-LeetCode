class Solution {
public:
   bool isZero(vector<int> &freq){
        for(auto f : freq)  if(f != 0)  return false;
        return true;
    }
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> v;
        for(auto a : arr)   v.push_back(a);
        sort(v.begin(), v.end());
        vector<int> freq(10, 0);
        int ans = 0;
        for(int i = 0; i < v.size(); ++i){
            freq[v[i]]++;
            freq[arr[i]]--;
            if(isZero(freq)) ans++;
        }
        return ans;
    }
};