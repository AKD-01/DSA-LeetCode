class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        string highPriorityPair = x > y ? "ab" : "ba";
        string lowPriorityPair = highPriorityPair == "ab" ? "ba" : "ab";

        string stringAfterFirstPass = removeSubstring(s, highPriorityPair);
        int removedPairsCount =
            (s.length() - stringAfterFirstPass.length()) / 2;

        totalScore += removedPairsCount * max(x, y);

        string stringAfterSecondPass =
            removeSubstring(stringAfterFirstPass, lowPriorityPair);
        removedPairsCount =
            (stringAfterFirstPass.length() - stringAfterSecondPass.length()) /
            2;

        totalScore += removedPairsCount * min(x, y);

        return totalScore;
    }

private:
    string removeSubstring(const string& input, const string& targetPair) {
        stack<char> charStack;

        for (char currentChar : input) {
            if (currentChar == targetPair[1] && !charStack.empty() &&
                charStack.top() == targetPair[0]) {
                charStack
                    .pop();  
            } else {
                charStack.push(currentChar);
            }
        }

        string remainingChars;
        while (!charStack.empty()) {
            remainingChars += charStack.top();
            charStack.pop();
        }
        reverse(remainingChars.begin(), remainingChars.end());
        return remainingChars;
    }
};