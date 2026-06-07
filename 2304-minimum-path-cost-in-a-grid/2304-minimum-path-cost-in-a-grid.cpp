class Solution {
public:
    int solve(int i, int j,
              vector<vector<int>>& grid,
              vector<vector<int>>& moveCost,
              vector<vector<int>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        if (i == m - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        int currVal = grid[i][j];

        for (int nextCol = 0; nextCol < n; nextCol++) { // to check every pos from next row

            ans = min(
                ans,
                currVal
                + moveCost[currVal][nextCol]
                + solve(i + 1, nextCol, grid, moveCost, dp)
            );
        }

        return dp[i][j] = ans;
    }

    int minPathCost(vector<vector<int>>& grid,
                    vector<vector<int>>& moveCost) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = INT_MAX;

        for (int j = 0; j < n; j++) { // to check every pos from first row
            ans = min(
                ans,
                solve(0, j, grid, moveCost, dp)
            );
        }

        return ans;
    }
};