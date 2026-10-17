class Solution {
public:
    int solve(int i, int j, string s, vector<vector<int>>& dp) {

        if (i >= j) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int ins = INT_MAX, insleft = INT_MAX, insright = INT_MAX;
        if (s[i] == s[j]) {
            ins = solve(i + 1, j - 1, s, dp);
        } else {

            insleft = 1 + solve(i + 1, j, s, dp);
            insright = 1 + solve(i, j - 1, s, dp);
        }
        ins = min({ins, insleft, insright});
        return dp[i][j] = ins;
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // return solve(0, n - 1, s, dp);

        for (int i = 0; i < n; i++)
            dp[i][i] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int ins = INT_MAX, insleft = INT_MAX, insright = INT_MAX;
                if (s[i] == s[j]) {
                    ins = dp[i + 1][j - 1];
                } else {
                    insleft = 1 + dp[i + 1][j];
                    insright = 1 +  dp[i][j - 1];
                }
                ins = min({ins, insleft, insright});
                dp[i][j] = ins;
            }
        }

        return dp[0][n-1];
    }
};