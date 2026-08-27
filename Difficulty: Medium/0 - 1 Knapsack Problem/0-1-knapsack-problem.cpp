class Solution {
	public:
	int solve(int n, vector<int> &val, vector<int> &wt, int W, vector<vector<int>> &dp) {
		if (n <= 0 || W <= 0)
			return 0;
		
		if (dp[n][W] != -1)
			return dp[n][W];
		
		int take = 0;
		if (wt[n - 1] <= W) {
			take = val[n - 1] + solve(n - 1, val, wt, W - wt[n - 1], dp);
		}
		int nottake = solve(n - 1, val, wt, W, dp);
		
		return dp[n][W] = max(take, nottake);
	}
	int knapsack(int W, vector<int> &val, vector<int> &wt) {
		// code here
		int n = val.size();
		vector<vector<int>> dp(n + 1, vector<int>(W + 1));
		
		vector<int> prev(W+1, 0);
		
		
		for (int i = 1; i <= n; i++) {
		    vector<int> curr(W+1, 0);
			for (int j = W; j >= 1; j--) {
				int take = 0;
				int nottake = 0;
				
				if(wt[i-1] <= j){
				    take = val[i-1] + prev[j - wt[i-1]];
				}
				nottake = prev[j];
			    prev[j] = max(take, nottake);
			}
// 			prev = curr;
		}
		
		return prev[W];
	}
};
