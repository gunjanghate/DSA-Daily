
class Solution {
public:
    long long solve(int i, int n, vector<int>& costs,
                    vector<long long>& dp) {

        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        long long ans = LLONG_MAX;

        for(int jump = 1; jump <= 3; jump++) {
            if(i + jump <= n) {
                long long cost = costs[i + jump - 1] +
                                 1LL * jump * jump +
                                 solve(i + jump, n, costs, dp);

                ans = min(ans, cost);
            }
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, -1);
        return (int)solve(0, n, costs, dp);
    }
};
