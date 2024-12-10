class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> m1;

        for (int i = 0; i < s.length(); i++) {
            string substring = "";
            substring += s[i];
            m1[substring]++;
            for (int j = i + 1; j < s.length(); j++) {
                substring += s[j];
                if (s[j]==s[i]){
                    m1[substring]++;
                }
                else{
                    break;
                }

            }
        }

        int res = -1;
        int maxlength = 0;

        for (auto itr : m1) {
            if (itr.second >= 3) {
                string temp = itr.first;
                if (temp.length() > maxlength) {
                    res = temp.length();
                    maxlength = temp.length();
                }
            }
        }

        return res;
    }
};