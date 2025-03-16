class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = 1LL * cars * cars * ranks[0];

        while (left < right) {
            long long mid = left + (right - left) / 2, count = 0;
            for (auto r : ranks) count += sqrt(1.0 * mid / r);
            
            if (count < cars) left = mid + 1;
            else right = mid;
        }

        return left;
    }
};
