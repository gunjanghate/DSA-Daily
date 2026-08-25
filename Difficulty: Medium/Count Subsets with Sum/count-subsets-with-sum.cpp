class Solution {
  public:
    int solve(int i, int t, int n, vector<int> arr, vector<vector<int>>& dp){
        if(i==n){
            if(t==0) return 1;
            else return 0;
        }
        if(dp[i][t]!=-1) return dp[i][t];
        
        int skip = solve(i+1, t, n, arr, dp);
        int notskip = 0;
        if(arr[i]<=t)  notskip = solve(i+1, t - arr[i], n, arr, dp);
        
        return dp[i][t] = skip+notskip;
         
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        
        return solve(0, target, n, arr, dp);
    }
};