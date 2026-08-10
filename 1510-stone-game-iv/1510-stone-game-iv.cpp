class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);

        for(int i = 1; i<=n; i++){
            for(int x = 1; x*x <=i; x++){
                int sq = x*x;

                if(dp[i - sq]==false){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};