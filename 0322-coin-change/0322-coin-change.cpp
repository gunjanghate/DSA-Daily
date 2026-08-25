class Solution {
public:
    int solve(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (i == 0) {
            if (amount % coins[i] == 0)
                return amount / coins[i];
            else
                return 1e9;
        }

        if (dp[i][amount] != -1)
            return dp[i][amount];
        int nottake = solve(i - 1, coins, amount, dp);

        int take = 1e9;
        if (coins[i] <= amount)
            take = 1 + solve(i, coins, amount - coins[i], dp);

        return dp[i][amount] = min(nottake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        vector<int> prev(amount+1, 0), curr(amount+1, 0);

        // int res = solve(n-1, coins, amount,dp);
        // return res >= 1e9 ? -1 : res;
        
        for (int i = 1; i <= amount; i++) {
            if (i % coins[0] == 0){
                prev[i] = i / coins[0];
                // curr[i] = i / coins[0];
            }
            else{
                prev[i] = 1e9;
                // curr[i] = 1e9;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int nottake = prev[j];
                int take = 1e9;
                if (coins[i] <= j)
                    take = 1 + curr[j - coins[i]];

                curr[j] = min(nottake, take);
            }

            prev = curr;
        }

        return prev[amount] >= 1e9 ? -1 : prev[amount] ;
    }
};