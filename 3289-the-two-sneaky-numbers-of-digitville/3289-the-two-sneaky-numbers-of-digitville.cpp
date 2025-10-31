class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> count;
        for (int x : nums) {
            count[x]++;
            if (count[x] == 2) {
                res.push_back(x);
            }
        }
        return res;
    }
};