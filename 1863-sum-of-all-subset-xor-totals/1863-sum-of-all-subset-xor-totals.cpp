class Solution {
public:
    int subsetXORSum(vector<int>& n) {
        return accumulate(begin(n), end(n), 0, bit_or<int>()) << (n.size() - 1);
    }
};