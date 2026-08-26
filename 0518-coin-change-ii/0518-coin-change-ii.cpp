class Solution {
public:
    int solve(int i, int amount, vector<int>& nums, vector<vector<int>>& dp){
        if(i==0){
            return amount % nums[0] == 0 ? 1 : 0;
        }
        if(amount==0) return 1;

        if(dp[i][amount]!=-1) return dp[i][amount];

        int notpick = solve(i-1, amount, nums, dp);

        int pick = 0;
        if(nums[i]<=amount) pick = solve(i, amount- nums[i], nums, dp);

        return dp[i][amount] = notpick + pick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));

        return solve(n-1, amount, coins, dp);
    }
};