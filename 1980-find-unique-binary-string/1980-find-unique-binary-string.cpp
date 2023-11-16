class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res = nums[0];
        int n = min(res.size(), nums.size());
        for (int i = 0; i < n; i++)
            res[i] = nums[i][i] == '0' ? '1' : '0';
        return res;
    }
};