class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt1 = count(s.begin(), s.end(), '1');

        vector<int> zeroBlocks;
        int i = 0;
        while (i < n) {
            int start = i;

            while (i < n && s[i] == s[start]) {
                ++i;
            }

            if (s[start] == '0') {
                zeroBlocks.push_back(i - start);
            }
        }

        int m = zeroBlocks.size();

        if (m < 2) {
            return cnt1;
        }

        int bestGain = 0;  // Optimal Increment
        for (int i = 0; i < m - 1; ++i) {
            bestGain = max(bestGain, zeroBlocks[i] + zeroBlocks[i + 1]);
        }

        return cnt1 + bestGain;
    }
};