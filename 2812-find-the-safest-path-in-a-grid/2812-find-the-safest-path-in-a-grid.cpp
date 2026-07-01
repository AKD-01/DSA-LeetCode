class Solution {
public:

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> multiSourceQueue;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    multiSourceQueue.push({i, j});
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = -1;
                }
            }
        }

        while (!multiSourceQueue.empty()) {
            int size = multiSourceQueue.size();
            while (size-- > 0) {
                auto curr = multiSourceQueue.front();
                multiSourceQueue.pop();
                for (auto& d : dir) {
                    int di = curr.first + d[0];
                    int dj = curr.second + d[1];
                    int val = grid[curr.first][curr.second];
                    if (isValidCell(grid, di, dj) && grid[di][dj] == -1) {
                        grid[di][dj] = val + 1;
                        multiSourceQueue.push({di, dj});
                    }
                }
            }
        }

        int start = 0;
        int end = 0;
        int res = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                end = max(end, grid[i][j]);
            }
        }
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isValidSafeness(grid, mid)) {
                res = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return res;
    }

private:

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isValidCell(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    bool isValidSafeness(vector<vector<int>>& grid, int minSafeness) {
        int n = grid.size();

        if (grid[0][0] < minSafeness || grid[n - 1][n - 1] < minSafeness) {
            return false;
        }

        queue<pair<int, int>> traversalQueue;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        traversalQueue.push({0, 0});
        visited[0][0] = true;

        while (!traversalQueue.empty()) {
            auto curr = traversalQueue.front();
            traversalQueue.pop();
            if (curr.first == n - 1 && curr.second == n - 1) {
                return true; 
            }
            for (auto& d : dir) {
                int di = curr.first + d[0];
                int dj = curr.second + d[1];
                if (isValidCell(grid, di, dj) && !visited[di][dj] &&
                    grid[di][dj] >= minSafeness) {
                    visited[di][dj] = true;
                    traversalQueue.push({di, dj});
                }
            }
        }

        return false; 
    }
};