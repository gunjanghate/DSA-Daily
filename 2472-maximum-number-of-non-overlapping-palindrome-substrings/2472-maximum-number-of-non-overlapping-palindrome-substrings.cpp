class Solution {
public:
    // bool isPalindrome(string s, int i, int j) {
    //     while (i < j) {
    //         if (s[i] != s[j])
    //             return false;
    //         i++, j--;
    //     }

    //     return true;
    // }
    // int solve(string s, int k, int i, int j, vector<vector<int>>& dp) {
    //     if (i >= s.length() || j >= s.length())
    //         return 0;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     if (isPalindrome(s, i, j)) {
    //         int take = 1 + solve(s, k, j + 1, j + k, dp);
    //         int grow = solve(s, k, i, j + 1, dp);
    //         int slide = solve(s, k, i + 1, j + 1, dp);

    //         return dp[i][j] = max({take, grow, slide});
    //     } else {
    //         int grow = solve(s, k, i, j + 1, dp);
    //         int slide = solve(s, k, i + 1, j + 1, dp);

    //         return dp[i][j] = max(grow, slide);
    //     }
    // }
    int maxPalindromes(string s, int k) {
        int n = s.length();
        if (k == 1)
            return n;
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // return solve(s, k, 0, k-1, dp);
        

        vector<vector<int>> t(n + 1, vector<int>(n + 1));
        vector<vector<bool>> isPalindrome(n + 1, vector<bool>(n + 1, false));

        for(int l = 1; l<=n; l++){
            for(int i = 0; i+l<=n; i++){
                int j = i + l - 1;
                if(i==j){
                    isPalindrome[i][j] = true;
                }else if(i+1 == j && s[i]==s[j]){
                    isPalindrome[i][j] = true;
                }else{
                    isPalindrome[i][j] = (s[i]==s[j]) && isPalindrome[i+1][j-1];
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (isPalindrome[i][j]) {
                    int takeIt = 1 + (j + k <= n ? t[j + 1][j + k] : 0);
                    int grow = t[i][j + 1];
                    int slide = t[i + 1][j + 1];

                    t[i][j] = max({takeIt, grow, slide});
                }

                int grow = t[i][j + 1];
                int slide = t[i + 1][j + 1];
                t[i][j] = max({t[i][j], grow, slide});
            }
        }

        return t[0][k-1];
    }
};