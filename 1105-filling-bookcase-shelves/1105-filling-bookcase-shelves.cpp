class Solution {
public:
    int width;
    vector<int> memo;

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        width = shelfWidth;
        memo = vector<int>(books.size(), -1);  
        return findHeight(books, 0);
    }
    int findHeight(vector<vector<int>>& books, int index) {
        if (index >= books.size())
            return 0;
        if (memo[index] != -1)
            return memo[index];
        int minHeight = INT_MAX;
        int currentWidth = 0;
        int currentHeight = 0;
        for (int i = index; i < books.size(); ++i) {
            if (currentWidth + books[i][0] <= width) {
                currentWidth += books[i][0];
                currentHeight = max(currentHeight, books[i][1]);
                minHeight = min(minHeight, currentHeight + findHeight(books, i + 1));
            } 
            else 
                break;
        }
        return memo[index] = minHeight;
    }
};