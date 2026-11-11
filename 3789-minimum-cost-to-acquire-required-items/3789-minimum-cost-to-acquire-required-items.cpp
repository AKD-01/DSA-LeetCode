class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        auto bound = [&](long long needA, int costA, long long needB, int costB) {
            int pA = min(costA, costBoth);  // a takes its full price
            int pB = min(costB, costBoth - pA);  // b gets what's left of the bundle
            return needA * pA + needB * pB;
        };
        return max(bound(need1, cost1, need2, cost2), bound(need2, cost2, need1, cost1));
    }
};