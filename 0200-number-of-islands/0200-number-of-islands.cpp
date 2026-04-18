class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j,
             int n, int m) {
        vis[i][j] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] &&
                grid[ni][nj] == '1') {
                dfs(grid, vis, ni, nj, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                cnt++;
                    dfs(grid, vis, i, j, n, m);
                }
            }
        }

        return cnt;
    }
};