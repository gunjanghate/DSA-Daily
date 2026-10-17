
class Solution {
public:
    int solve(int i, int j, int n, int m,
              string& w1, string& w2,
              vector<vector<int>>& dp) {

        if (i == n) return m - j;
        if (j == m) return n - i;

        if (dp[i][j] != -1) return dp[i][j];

        if (w1[i] == w2[j]) {
            return dp[i][j] =
                solve(i + 1, j + 1, n, m, w1, w2, dp);
        }

        int ins = 1 + solve(i, j + 1, n, m, w1, w2, dp);
        int rep = 1 + solve(i + 1, j + 1, n, m, w1, w2, dp);
        int del = 1 + solve(i + 1, j, n, m, w1, w2, dp);

        return dp[i][j] = min({ins, rep, del});
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, n, m, word1, word2, dp);
    }
};