class Solution {
public:
    long countOfSubstrings(string word, int k) {
        return countK(word, k) - countK(word, k + 1);
    }

private:
    long countK(string word, int k) {
        long count = 0;
        int left = 0, right = 0, consonants = 0;
        unordered_map<char, int> vowels;

        while (right < word.length()) {
            char ch = word[right];
            if (isVowel(ch)) vowels[ch]++;
            else consonants++;

            while (vowels.size() == 5 && consonants >= k) {
                count += word.length() - right;
                char leftChar = word[left];
                if (isVowel(leftChar)) {
                    if (--vowels[leftChar] == 0) vowels.erase(leftChar);
                } else consonants--;
                left++;
            }

            right++;
        }

        return count;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
