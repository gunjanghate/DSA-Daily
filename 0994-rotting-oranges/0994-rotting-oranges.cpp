class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;

        while (true) {
            vector<vector<int>> newGrid = grid;
            bool changed = false;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {

                    if (grid[i][j] == 2) {

                        // DOWN
                        if (i + 1 < n && grid[i + 1][j] == 1) {
                            newGrid[i + 1][j] = 2;
                            changed = true;
                        }

                        // UP
                        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                            newGrid[i - 1][j] = 2;
                            changed = true;
                        }

                        // RIGHT
                        if (j + 1 < m && grid[i][j + 1] == 1) {
                            newGrid[i][j + 1] = 2;
                            changed = true;
                        }

                        // LEFT
                        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                            newGrid[i][j - 1] = 2;
                            changed = true;
                        }
                    }
                }
            }

            if (!changed) break;

            grid = newGrid;
            time++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return time;
    }
};