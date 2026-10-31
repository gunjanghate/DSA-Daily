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
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int> (3, -1)));

        return solve(m , n , grid, 0, 0, 0, dp);
    }
};