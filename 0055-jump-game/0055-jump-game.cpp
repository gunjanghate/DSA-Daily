class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> dp(n, false);

        dp[n - 1] = true;

        for (int i = n - 2; i >= 0; i--) {

            for (int jump = 1; jump <= nums[i]; jump++) {

                if (i + jump < n && dp[i + jump]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};