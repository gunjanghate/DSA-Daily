class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int n, int k, int i, vector<vector<int>>& dp) {
        if (i >= n)
            return 0;
        if (k == 0)
            return 1;

        if (dp[i][k] != -1)
            return dp[i][k];

        long long skip = solve(n, k, i + 1, dp);
        long long take = 0;
        for (int j = i + 1; j < n; j++) {
            take += solve(n, k - 1, j, dp);
        }

        return dp[i][k] = (skip + take) % MOD;
    }
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        for (int l = 1; l <= k; l++) {

            vector<int> prev(n + 1, 0);
            for (int x = n - 1; x >= 0; x--) {
                prev[x] = (prev[x + 1] + dp[l - 1][x]) % MOD;
            }

            for (int i = n - 1; i >= 0; i--) {

                long long skip = dp[l][i+1];
                long long take = prev[i+1];

                dp[l][i] = (skip + take) % MOD;
            }
        }

        return dp[k][0];
    }
};