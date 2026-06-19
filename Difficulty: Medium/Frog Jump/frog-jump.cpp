class Solution {
  public:
  
    int solve(int idx, vector<int>& dp, vector<int>& height){
        if(idx==0) return 0;
        if(dp[idx]!= -1) return dp[idx];
        
        int left = solve(idx - 1 , dp, height) + abs(height[idx] - height[idx-1]);
        int right = INT_MAX;
        
        if(idx > 1) right = solve(idx - 2 , dp, height) + abs(height[idx] - height[idx-2]);
        
        
        return dp[idx]= min(left, right);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n+1, -1);
        
        return solve(n - 1 , dp, height);
        
    }
};