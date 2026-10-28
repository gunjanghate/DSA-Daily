class Solution {
public:
    int solve(int i, int j, int xr, int n, int m,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        xr ^= grid[i][j];

        if (i == n - 1 && j == m - 1) {
            return xr;
        }

        if (dp[i][j][xr] != -1) {
            return dp[i][j][xr];
        }

        int ans = INT_MAX;

        if (j + 1 < m) {
            ans = min(ans, solve(i, j + 1, xr, n, m, grid, dp));
        }

        if (i + 1 < n) {
            ans = min(ans, solve(i + 1, j, xr, n, m, grid, dp));
        }

        return dp[i][j][xr] = ans;
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(
                m, vector<int>(1024, -1)
            )
        );

        return solve(0, 0, 0, n, m, grid, dp);
    }
};