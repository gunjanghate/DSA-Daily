class Solution {
public:
    int stoneGameV(vector<int>& s) {

        int n = s.size();

        // Prefix sum
        vector<int> pre(n);

        pre[0] = s[0];

        for(int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + s[i];

        // dp[i][j] = maximum score from s[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Length 2, 3, 4, ...
        for(int len = 2; len <= n; len++) {

            for(int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                for(int k = i; k < j; k++) {

                    int left =
                        pre[k] - (i > 0 ? pre[i - 1] : 0);

                    int right =
                        pre[j] - pre[k];

                    if(left < right) {

                        dp[i][j] = max(
                            dp[i][j],
                            left + dp[i][k]
                        );

                    }
                    else if(right < left) {

                        dp[i][j] = max(
                            dp[i][j],
                            right + dp[k + 1][j]
                        );

                    }
                    else {

                        dp[i][j] = max({
                            dp[i][j],
                            left + dp[i][k],
                            right + dp[k + 1][j]
                        });
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};