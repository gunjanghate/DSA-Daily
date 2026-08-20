class Solution {
  public:
    int solve(int i, vector<int> &val, vector<int> &wt, int W, vector<vector<int>> &dp){
        if(i>=val.size() || W<=0) return 0;
        
        if(dp[i][W]!=-1) return dp[i][W];
        
        int take = 0;
        if(wt[i]<=W){
            take = val[i] + solve(i+1, val, wt, W-wt[i], dp); 
        }
        int nottake = 0;
        nottake = solve(i+1, val, wt, W, dp);
        
        
        return dp[i][W] = max(take, nottake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1,-1));
        
        
        return solve(0, val, wt, W, dp);
    }
};