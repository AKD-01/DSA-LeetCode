class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> numSet(arr.begin(), arr.end());

        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int prev = arr[j], curr = arr[i] + arr[j], len = 2;

                while (numSet.count(curr)) {
                    int temp = curr;
                    curr += prev;
                    prev = temp;
                    maxLen = max(maxLen, ++len);
                }
            }
        }

        return maxLen;
    }
};