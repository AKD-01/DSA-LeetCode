class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxPile = *max_element(candies.begin(), candies.end());
        int left = 0, right = maxPile;

        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (canDistribute(candies, k, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

private:
    bool canDistribute(vector<int>& candies, long long k, int portion) {
        long long count = 0;
        for (int c : candies) count += c / portion;
        return count >= k;
    }
};
