class Solution {
	public:
	int solve(int i, vector<int>& val, vector<int>& wt, int capacity, vector<vector<int>> & dp) {
		
		if (i<0 || capacity <= 0) {
			return 0;
		}
		
		if (dp[i][capacity] != -1)
			return dp[i][capacity];
		
		int notpick = solve(i - 1, val, wt, capacity, dp);
		int pick = 0;
		if (wt[i] <= capacity)
			pick = val[i] + solve(i, val, wt, capacity - wt[i], dp);
		
		return dp[i][capacity] = max(notpick, pick);
	}
	int knapSack(vector<int>& val, vector<int>& wt, int c) {
		// code here
		int n = val.size();
		
		vector<vector<int>> dp(n + 1, vector<int>(c + 1, -1));
		
		// return solve(n-1, val, wt, capacity, dp);
		vector<int> prev(c + 1, 0), curr(c + 1, 0);
		
		for(int i = 1; i<=c; i++){
		    prev[i] = ((int) i / wt[0])  * val[0];
		}

		for (int i = 1; i<n; i++) {
			for (int j = 0; j <= c; j++) {
				int notpick = prev[j];
				int pick = 0;
				if (wt[i] <= j)
					pick = val[i] + curr[j - wt[i]];
				
			    curr[j] = max(notpick, pick);
			}
			prev = curr;
		}
		
		return prev[c];
	}
};
