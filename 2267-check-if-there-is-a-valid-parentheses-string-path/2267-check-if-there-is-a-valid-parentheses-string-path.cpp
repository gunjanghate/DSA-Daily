class Solution {
public:
    bool solve(int i, int j, int n, int m,
               vector<vector<char>>& grid, int c,
               vector<vector<vector<int>>>& dp) {

        if(i >= n || j >= m)
            return false;

        if(grid[i][j] == '(')
            c++;
        else
            c--;

        if(c < 0)
            return false;

        if(i == n - 1 && j == m - 1)
            return c == 0;

        if(dp[i][j][c] != -1)
            return dp[i][j][c];

        bool right = solve(i + 1, j, n, m, grid, c, dp);
        bool down = solve(i, j + 1, n, m, grid, c, dp);

        return dp[i][j][c] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m, vector<int>(n + m + 1, -1))
        );


        if(grid[0][0] == ')')
            return false;

        return solve(0, 0, n, m, grid, 0, dp);
    }
};