class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        if (n == 1) {
            return s > target ? s : "";
        }

        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        string oddChar = "";
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                if (oddChar != "") {
                    return "";
                }
                oddChar = string(1, 'a' + i);
            }
            cnt[i] /= 2; 
        }

        string prefix = "";

        auto check = [&](char c) -> bool {
            string left = prefix;
            left.push_back(c);
            for (int i = 25; i >= 0; i--) {
                left.append(cnt[i], 'a' + i);
            }

            string palindrome = left + oddChar;
            string reversed_left = left;
            reverse(reversed_left.begin(), reversed_left.end());
            palindrome += reversed_left;

            return palindrome > target;
        };

        for (int i = 0; i < n / 2; i++) {
            bool found = false;
            for (int j = 0; j < 26; j++) {
                if (cnt[j] == 0) {
                    continue;
                }

                cnt[j]--;
                if (check('a' + j)) {
                 
                    prefix.push_back('a' + j);
                    found = true;
                    break;
                } else {
                    cnt[j]++;  
                }
            }
            if (!found) {
                return "";  
            }

            if (prefix[i] >
                target[i]) {  
                string left = prefix;
                for (int j = 0; j < 26; j++) {
                    left.append(cnt[j], 'a' + j);
                }
                string palindrome = left + oddChar;
                string reversed_left = left;
                reverse(reversed_left.begin(), reversed_left.end());
                palindrome += reversed_left;
                return palindrome;
            }
        }

        string ans = prefix + oddChar;
        string reversed_prefix = prefix;
        reverse(reversed_prefix.begin(), reversed_prefix.end());
        ans += reversed_prefix;
        return ans;
    }
};