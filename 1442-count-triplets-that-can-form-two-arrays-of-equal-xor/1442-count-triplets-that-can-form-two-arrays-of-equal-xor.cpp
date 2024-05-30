class Solution {
public:
    int countTriplets(vector<int>& arr) {
        map<int, pair<int, int>> xorMap;  
        xorMap[0] = make_pair(1, 0);
        
        int x = 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            x ^= arr[i];
            if (xorMap.find(x) != xorMap.end()) {
                int cnt = xorMap[x].first, sum = xorMap[x].second;
                ans += i * cnt - sum;
            }
            xorMap[x].first++;
            xorMap[x].second += i + 1;
        }
        
        return ans;  
    }
};