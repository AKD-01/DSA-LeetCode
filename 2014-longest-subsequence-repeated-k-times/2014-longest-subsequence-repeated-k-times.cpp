class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        vector<char> candidate;
        for (int i = 25; i >= 0; i--) {
            if (freq[i] >= k) {
                candidate.push_back('a' + i);
            }
        }
        queue<string> q;
        for (char ch : candidate) {
            q.push(string(1, ch));
        }

        string ans = "";
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            if (curr.size() > ans.size()) {
                ans = curr;
            }
            // generate the next candidate string
            for (char ch : candidate) {
                string next = curr + ch;
                if (isKRepeatedSubsequence(s, next, k)) {
                    q.push(next);
                }
            }
        }

        return ans;
    }

    bool isKRepeatedSubsequence(const string& s, const string& t, int k) {
        int pos = 0, matched = 0;
        int n = s.size(), m = t.size();
        for (char ch : s) {
            if (ch == t[pos]) {
                pos++;
                if (pos == m) {
                    pos = 0;
                    matched++;
                    if (matched == k) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};