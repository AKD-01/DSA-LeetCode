class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26] = {}, res = 0;
  for (auto ch : chars) 
      ++cnt[ch - 'a'];
  for (auto &w : words) {
    int cnt1[26] = {}, match = true;
    for (auto ch : w)
      if (++cnt1[ch - 'a'] > cnt[ch - 'a']) {
        match = false;
        break;
      }
    if (match) 
        res += w.size();
  }
  return res;
    }
};