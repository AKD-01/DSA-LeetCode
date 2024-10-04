class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int left = 0, right = skill.size() - 1;
        int teamSkill = skill[left] + skill[right];
        long long totalChemistry = 0;

        while (left < right) {
            if (teamSkill != skill[left] + skill[right]) {
                return -1;
            }
            totalChemistry += (long long)skill[left] * skill[right];
            left++;
            right--;
        }

        return totalChemistry;
    }
};