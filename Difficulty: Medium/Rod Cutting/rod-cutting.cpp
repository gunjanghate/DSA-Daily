class Solution {
  public:
    int solve(int i, vector<int>& price, int k, vector<vector<int>>& dp){
        if(i==0){
            return k * price[0];
        }
        
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        
        int notskip = solve(i-1, price, k, dp);
        int skip = 0;
        int l = i+1;
        if(l<=k){
            skip = price[i] + solve(i, price, k - l, dp);
        }
        
        return dp[i][k] = max(notskip, skip);
        
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        int k = n;
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(n-1, price, k, dp);
    }
};