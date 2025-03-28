class Solution {
public:
    static constexpr int DIR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int qSize = queries.size(), rows = grid.size(), cols = grid[0].size();
        int total = rows * cols;
        vector<int> res(qSize), maxPts(total + 1);
        vector<vector<int>> minVal(rows, vector<int>(cols, INT_MAX));

        minVal[0][0] = grid[0][0];
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> minHeap;
        minHeap.push({grid[0][0], 0, 0});
        int count = 0;

        while (!minHeap.empty()) {
            auto [val, r, c] = minHeap.top();
            minHeap.pop();
            maxPts[++count] = val;

            for (const auto& d : DIR) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && minVal[nr][nc] == INT_MAX) {
                    minVal[nr][nc] = max(val, grid[nr][nc]);
                    minHeap.push({minVal[nr][nc], nr, nc});
                }
            }
        }

        for (int i = 0; i < qSize; i++) {
            int thr = queries[i], left = 0, right = total;
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (maxPts[mid] < thr) left = mid;
                else right = mid - 1;
            }
            res[i] = left;
        }

        return res;
    }
};
