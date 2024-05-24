class Solution {
    int ans = 0;
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26, 0), used(26, 0);
        for (auto & c : letters) {
            count[c-'a']++;
        }
        backtrack(words, score, count, used, 0, 0);
        return ans;
    }
    void backtrack(vector<string>& words, vector<int>& score, vector<int> &count, vector<int> &used, int pos, int reward) {
        for (int i = 0; i < 26; ++i) {
            if (used[i] > count[i])
                return;
        }
        ans = max(reward, ans);
        for (int i = pos; i < words.size(); ++i) {
            for (auto & c : words[i]) {
                used[c-'a']++;
                reward += score[c-'a'];
            }
            backtrack(words, score, count, used, i+1, reward);
            for (auto & c : words[i]) {
                used[c-'a']--;
                reward -= score[c-'a'];
            }
        }
    }
};