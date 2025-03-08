class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0, whiteCount = 0, minRecolors = INT_MAX;

        for (int right = 0; right < blocks.size(); right++) {
            if (blocks[right] == 'W') whiteCount++;

            if (right - left + 1 == k) {
                minRecolors = min(minRecolors, whiteCount);
                if (blocks[left] == 'W') whiteCount--;
                left++;
            }
        }
        return minRecolors;
    }
};