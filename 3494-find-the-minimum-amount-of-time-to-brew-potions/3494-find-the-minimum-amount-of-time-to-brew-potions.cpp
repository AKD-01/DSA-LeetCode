class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> f(n + 1, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                f[j + 1] = max(f[j + 1], f[j]) + mana[i] * skill[j];
            }
            for (int j = n - 1; j > 0; j--) {
                f[j] = f[j + 1] - mana[i] * skill[j];
            }
        }
        return f.back();
    }
};