class Solution {
    public:
        vector<string> wordBreak(string s, vector<string>& wordDict) 
        {
            int max_len = 0;
            unordered_set<string> dict;
            for(string& str : wordDict)
            {
                dict.insert(str);
                max_len = max(max_len, (int)str.length());
            }

            unordered_map<int, vector<string>> mp;
            return break_word(s, 0, dict, max_len, mp);
        }

    protected:
        vector<string> break_word(  const string& s, int n, unordered_set<string>& dict, 
                                    int max_len, unordered_map<int, vector<string>>& mp)
        {
            if(mp.count(n)) return mp[n];

            string str;
            for(int i = n; i < s.length() && str.length() <= max_len; ++i)
            {
                str += s[i];
                if(dict.count(str))
                {
                    if(i == s.length()-1)
                        mp[n].push_back(str);
                    else
                    {
                        vector<string> vs = break_word(s, i+1, dict, max_len, mp);
                        for(auto& a : vs) mp[n].push_back(str + " " + a);
                    }
                }
            }
            return mp[n];
        }
};