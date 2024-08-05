class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
       unordered_map < string ,int> mp;
        int cnt = 0;
        for(string ch : arr){
            mp[ch]++;
        }
        for(string ch:arr){
            if(mp[ch] == 1) cnt++;
            if(cnt == k) return ch;
        }
        return ""; 
    }
};