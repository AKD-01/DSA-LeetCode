class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> pos;
        pos[0] = -1;
        int n = arr.size();
        int s = 0;
        int ans = n + 1;
        int minL = n;
        for (int i = 0; i < n; i++) {
            s += arr[i];
            if (pos.count(s - target)) {
                int j = pos[s - target];
                int l = i - j;
                ans = min(ans, l + (j == -1 ? n : arr[j]));
                minL = min(minL, l);
            }
            arr[i] = minL;
            pos[s] = i;
        }

        return ans == n + 1 ? -1 : ans;
    }
};