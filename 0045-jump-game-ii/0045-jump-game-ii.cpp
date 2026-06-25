class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, 1e9);

        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {

            for (int jump = 1;
                 jump <= nums[i];
                 jump++) {

                if (i + jump < n) {
                    dp[i] = min(dp[i],
                               1 + dp[i + jump]);
                }
            }
        }

        return dp[0];
    }
};