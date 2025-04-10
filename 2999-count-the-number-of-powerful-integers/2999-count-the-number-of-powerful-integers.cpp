class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long end, int lim, string suf) {
        string startStr = to_string(start - 1), endStr = to_string(end);
        return count(endStr, suf, lim) - count(startStr, suf, lim);
    }

    long long count(string num, string suf, int lim) {
        if (num.length() < suf.length()) return 0;
        if (num.length() == suf.length()) return num >= suf ? 1 : 0;

        string last = num.substr(num.length() - suf.length());
        long long ans = 0;
        int preLen = num.length() - suf.length();

        for (int i = 0; i < preLen; i++) {
            if (lim < (num[i] - '0')) {
                ans += (long)pow(lim + 1, preLen - i);
                return ans;
            }
            ans += (long)(num[i] - '0') * (long)pow(lim + 1, preLen - 1 - i);
        }
        if (last >= suf) ans++;
        return ans;
    }
};
