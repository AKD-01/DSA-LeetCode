class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 2; i++) {
            int product = arr[i] * arr[i + 1] * arr[i + 2];
            if (product % 2 == 1) return true;
        }
        return false;
    }
};