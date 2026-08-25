class Solution {
	public:
	int solve(int i, int t, int n, vector<int> arr, vector<vector<int>> & dp) {
		if (i == 0) {
			if (t == 0 && arr[0]==0)
				return 2;
			if(t==0 || arr[0]==t)
			    return 1;
			
				return 0;
		}
		if (dp[i][t] != -1)
			return dp[i][t];
		
		int skip = solve(i - 1, t, n, arr, dp);
		int notskip = 0;
		if (arr[i] <= t)
			notskip = solve(i - 1, t - arr[i], n, arr, dp);
		
		return dp[i][t] = skip + notskip;
		
	}
	int help(vector<int>& arr, int target) {
		int n = arr.size();
		vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
		
		return solve(n-1, target, n, arr, dp);
	}
	int countPartitions(vector<int>& arr, int diff) {
		// Code here
		// d = s1 - s2
		// ts = s1 + s2
		// d = ts - s2 - s2
		// d = ts - 2s2
		// s2 = (ts - d )/ 2;
		int ts = accumulate(arr.begin(), arr.end(), 0);
		
		if((ts-diff) < 0 || (ts -diff)%2 !=0) return 0;
		
		return help(arr, (ts-diff)/2);
		
	}
};
