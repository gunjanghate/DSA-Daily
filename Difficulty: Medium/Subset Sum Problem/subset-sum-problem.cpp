class Solution {
public:
    bool solve(int i, vector<int>& arr, int sum, vector<vector<int>>& dp) {
        if (sum == 0)
            return true;

        if (i == 0)
            return arr[0] == sum;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        bool noTake = solve(i - 1, arr, sum, dp);

        bool take = false;
        if (arr[i] <= sum) {
            take = solve(i - 1, arr, sum - arr[i], dp);
        }

        return dp[i][sum] = noTake || take;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return solve(n - 1, arr, sum, dp);
    }
};