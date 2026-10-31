class Solution {

const int MOD = 1e9 + 7;
public:
    int solve(int m, int n, vector<vector<int>>& grid, int i, int j, int k, vector<vector<vector<int>>>& dp){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1){
            return 1;
        }

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        int right = 0, down = 0;

        if(grid[i][j] == 0){
            right = solve(m, n, grid, i, j+1, 1, dp);
            down = solve(m, n, grid, i+1, j, 2, dp);
        }else{
            if(k==1){
                down = solve(m , n, grid, i+1, j, 2, dp);
            }else{
                right = solve(m , n, grid, i, j+1, 1, dp);
            }
        }

        return dp[i][j][k] = (right + down) % MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int> (3, 0)));

        // return solve(m , n , grid, 0, 0, 0, dp);
        
        dp[m-1][n-1][0] = 1;
        dp[m-1][n-1][1] = 1;
        dp[m-1][n-1][2] = 1;

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {

                if (i == m-1 && j == n-1) continue;

                for (int k = 0; k < 3; k++) {

                    int right = 0;
                    int down = 0;

                    if (grid[i][j] == 0) {

                        if (j+1 < n)
                            right = dp[i][j+1][1];

                        if (i+1 < m)
                            down = dp[i+1][j][2];

                    } 
                    else {
                        if (k == 1) {
                            if (i+1 < m)
                                down = dp[i+1][j][2];
                        }
                        else {
                            if (j+1 < n)
                                right = dp[i][j+1][1];
                        }
                    }

                    dp[i][j][k] = (right + down) % MOD;
                }
            }
        }

        return dp[0][0][0];
    }
};