class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        
        for (auto& num : arr) num %= 2;
        
        vector<int> even(n), odd(n);
        
        if (arr[n - 1] == 0) even[n - 1] = 1;
        else odd[n - 1] = 1;
        
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] == 1) {
                odd[i] = (1 + even[i + 1]) % MOD;
                even[i] = odd[i + 1];
            } else {
                even[i] = (1 + even[i + 1]) % MOD;
                odd[i] = odd[i + 1];
            }
        }
        
        int count = 0;
        for (auto o : odd) count = (count + o) % MOD;
        
        return count;
    }
};
