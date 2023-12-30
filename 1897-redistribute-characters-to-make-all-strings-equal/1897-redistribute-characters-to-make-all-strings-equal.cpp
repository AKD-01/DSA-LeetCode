class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnt[26] = {};
        for (auto &w : words)
        for (auto ch : w) ++cnt[ch - 'a'];
        return all_of(begin(cnt), end(cnt), [&](int c) { return c % words.size() == 0; });
    }
};