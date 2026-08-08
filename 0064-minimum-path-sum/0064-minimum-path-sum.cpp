class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i>=m || j>=n) return 1e9;
        if(i==m-1 && j==n-1) return grid[i][j];

        if(dp[i][j]!=0) return dp[i][j];

        return dp[i][j] = grid[i][j] +  min(
            solve(i+1, j, m, n, grid, dp),
            solve(i, j+1, m, n, grid, dp)
        );
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        vector<int> prev(m, 0);
        for(int i = 0; i<m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j<n; j++){
                if(i==0 && j==0) curr[j] = grid[0][0];
                else{
                    int up = grid[i][j];
                    if(i>0) up += prev[j];
                    else up += 1e9;
                    int left = grid[i][j];
                    if(j>0) left += curr[j-1];
                    else left += 1e9;

                    curr[j] = min(up, left);
                }
            }

            prev = curr;
        }

        return prev[n-1];
    }
};