class Solution {
  public:
    int dfs(int i, int j, int n, int m, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(i==n-1 && j==m-1) return mat[i][j];
        if(i>=n || j>=m || j < 0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down = dfs(i+1, j, n, m , mat, dp);
        int dialeft = dfs(i+1, j-1, n, m , mat, dp);
        int diaright = dfs(i+1, j+1, n, m , mat, dp);
        
        return dp[i][j] = mat[i][j] + max({down, dialeft, diaright});
    }
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int ans = INT_MIN;
        for(int i = 0; i<m; i++){
            ans =  max(ans, dfs(0,i,n,m,mat,dp));
        }
        
        return ans;
        
    }
};