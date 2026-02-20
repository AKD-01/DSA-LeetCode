class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> blocks;
        int count = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') count++;
            else count--;

            if (count == 0) {
                string inside = s.substr(start + 1, i - start - 1);
                string processed = makeLargestSpecial(inside);

                blocks.push_back("1" + processed + "0");

                start = i + 1;
            }
        }

        sort(blocks.rbegin(), blocks.rend());

        string result = "";
        for (auto &b : blocks) {
            result += b;
        }
        return result;
    }
};
