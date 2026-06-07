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
        return solve(m, n, o, 0, 0, dp);
    }
};