class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> numCnt;
        unordered_map<int, int> numPartialCnt;

        numCnt.reserve(nums.size() * 2);
        numPartialCnt.reserve(nums.size() * 2);

        for (int v : nums) {
            numCnt[v]++;
        }

        int ans = 0;
        for (int v : nums) {
            int target = v * 2;
            int lCnt = numPartialCnt[target];
            numPartialCnt[v]++;
            int rCnt = numCnt[target] - numPartialCnt[target];
            ans = (ans + (lCnt * 1LL * rCnt % MOD)) % MOD;
        }

        return ans;
    }
};