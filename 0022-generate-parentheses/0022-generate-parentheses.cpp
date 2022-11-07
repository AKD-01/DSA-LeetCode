class Solution {
    map<pair<int, int>, vector<string>> memo;
public:
    vector<string>& helper(int n, int left = 0, int right = 0) {
        if (left == n && right == n) return memo[{ n, n }];
        if (auto it = memo.find({ left, right }); it != end(memo)) return it->second;
        
        vector<string> result;
        if (left < n) {
            auto& res = helper(n, left + 1, right);
            for (auto& r : res) {
                result.push_back("(" + r);
            }
        }
        if (right < left) {
            auto& res = helper(n, left, right + 1);
            for (auto& r : res) {
                result.push_back(")" + r);
            }
        }
        
        return memo[{ left, right }] = result;
    }
    vector<string> generateParenthesis(int n) {
        memo[{ n, n }] = { "" };
        return move(helper(n));
    }
};