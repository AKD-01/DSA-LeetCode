class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
       unordered_map<int,int> mp;
        for(int ele : arr){
            // for -ve number it will work correctly
            ele = ((ele % k) + k) % k;
            mp[ele]++;
        }
        // 2nd part
        if(mp.find(0) != mp.end()) {
            // if the freq.. of 0 is not even
            if(mp[0] % 2 != 0) return false;
            mp.erase(0);
        }
        for(auto x : mp) {
            int ele = x.first;
            int rem = k - x.first;
            if(mp.find(rem) == mp.end()) return false;
            if(mp[ele] != mp[rem]) return false;
        }
        return true; 
    }
};