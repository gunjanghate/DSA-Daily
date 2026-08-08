class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& o , int i, int j, vector<vector<int>> &dp){
        if(i >= m || j >= n || (o[i][j]==1)) return 0;
        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] =
            solve(m, n, o, i+1, j, dp) +
            solve(m, n, o, i, j+1, dp);

    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m = o.size();
        int n = o[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if(o[0][0]==1) return 0;

        dp[0][0] = 1;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i==0 && j==0) continue;
                if(o[i][j]==1){
                    dp[i][j] = 0;
                    continue;
                }

                int up = 0;
                if(i>0) up += dp[i-1][j];
                int left = 0;
                if(j>0) left += dp[i][j-1];

                dp[i][j] = up + left;
            }
        }

        return dp[m-1][n-1];
    }
};