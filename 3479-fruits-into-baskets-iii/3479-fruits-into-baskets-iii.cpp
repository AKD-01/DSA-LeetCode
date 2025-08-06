class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int m = sqrt(n);
        int section = (n + m - 1) / m;
        int count = 0;
        vector<int> maxV(section);
        for (int i = 0; i < n; i++) {
            maxV[i / m] = max(maxV[i / m], baskets[i]);
        }
        for (int fruit : fruits) {
            int sec;
            int unset = 1;
            for (sec = 0; sec < section; sec++) {
                if (maxV[sec] < fruit) {
                    continue;
                }
                int choose = 0;
                maxV[sec] = 0;
                for (int i = 0; i < m; i++) {
                    int pos = sec * m + i;
                    if (pos < n && baskets[pos] >= fruit && !choose) {
                        baskets[pos] = 0;
                        choose = 1;
                    }
                    if (pos < n) {
                        maxV[sec] = max(maxV[sec], baskets[pos]);
                    }
                }
                unset = 0;
                break;
            }
            count += unset;
        }
        return count;
    }
};