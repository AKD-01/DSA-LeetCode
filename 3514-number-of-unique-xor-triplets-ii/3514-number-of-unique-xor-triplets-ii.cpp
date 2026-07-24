class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int m = 0;
        for (int v : nums) {
            m = max(m, v);
        }
        int u = 1;
        while (u <= m) {
            u <<= 1;
        }
        vector<int> s(u);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                s[nums[i] ^ nums[j]] = 1;
            }
        }
        vector<int> t(u);
        for (int x = 0; x < u; x++) {
            if (!s[x]) {
                continue;
            }
            for (int v : nums) {
                t[x ^ v] = 1;
            }
        }
        int ans = 0;
        for (int x = 0; x < u; x++) {
            if (t[x]) {
                ans++;
            }
        }
        return ans;
    }
};