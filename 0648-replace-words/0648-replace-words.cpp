class trie {
public:
    bool terminal;
    trie* next[26];
    trie() {
        terminal = false;
        for (int i = 0; i < 26; i++) next[i] = NULL;
    }
};
class Solution {
    trie* base = new trie();

    void insert(string word) {
        int len = word.size();
        trie* iter = base;
        for (int i = 0; i < len; i++) {
            if (!iter->next[word[i] - 97]) {
                iter->next[word[i] - 97] = new trie();
            }
            iter = iter->next[word[i] - 97];
        }
        iter->terminal = true;
    }
    string search(string &word) {
        int len = word.size();
        string cu;
        trie* iter = base;
        for (int i = 0; i < len; i++) {
            if (!iter->next[word[i] - 97]) {
                if (iter->terminal) return cu;
                return word;
            }
            cu += word[i];
            iter = iter->next[word[i] - 97];
            if (iter->terminal) return cu;
        }
        return cu;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        string ret, t;
        for (string i: dictionary) insert(i);
        for (char i: sentence) {
            if (i == ' ') {
                ret += search(t);
                ret += ' ';
                t.clear();
            } else {
                t += i;
            }
        }
        ret += search(t);
        return ret;
    }
};