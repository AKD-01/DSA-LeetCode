class Solution {
public:
    const int UNGUARDED = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;

    void markguarded(int row, int col, vector<vector<int>>& grid) {
        // Traverse upwards
        for (int r = row - 1; r >= 0; r--) {
            if (grid[r][col] == WALL || grid[r][col] == GUARD) break;
            grid[r][col] = GUARDED;
        }
        // Traverse downwards
        for (int r = row + 1; r < grid.size(); r++) {
            if (grid[r][col] == WALL || grid[r][col] == GUARD) break;
            grid[r][col] = GUARDED;
        }
        // Traverse leftwards
        for (int c = col - 1; c >= 0; c--) {
            if (grid[row][c] == WALL || grid[row][c] == GUARD) break;
            grid[row][c] = GUARDED;
        }
        // Traverse rightwards
        for (int c = col + 1; c < grid[row].size(); c++) {
            if (grid[row][c] == WALL || grid[row][c] == GUARD) break;
            grid[row][c] = GUARDED;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));

        // Mark guards' positions
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }

        // Mark walls' positions
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }

        // Mark cells as guarded by traversing from each guard
        for (const auto& guard : guards) {
            markguarded(guard[0], guard[1], grid);
        }

        // Count unguarded cells
        int count = 0;
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                if (cell == UNGUARDED) count++;
            }
        }
        return count;
    }
};