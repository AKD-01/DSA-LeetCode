class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;
        for(int i=0;i<s.size();i++){
            map1[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            map2[t[i]]++;
        }
        for(int i=0;i<max(t.size(),s.size());i++){
            if(map1[t[i]]!=map2[t[i]])
                return false;
        }
        return true;    
    }
};