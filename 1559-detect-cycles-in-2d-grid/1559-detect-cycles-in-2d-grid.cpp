class Solution {
public:
    void solve(vector<vector<char>>& grid, int i, int j,
               int parent_i, int parent_j,
               int n, int m, bool& ans,
               vector<vector<int>>& visited) {
        
        visited[i][j] = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                continue;

            // only move on same character
            if (grid[ni][nj] != grid[i][j])
                continue;

            // if not visited → go deeper
            if (!visited[ni][nj]) {
                solve(grid, ni, nj, i, j, n, m, ans, visited);
            }
            // if visited AND not parent → cycle found
            else if (ni != parent_i || nj != parent_j) {
                ans = true;
                return;
            }
        }
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        bool ans = false;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    solve(grid, i, j, -1, -1, n, m, ans, visited);
                }
                if (ans) return true;
            }
        }

        return false;
    }
};