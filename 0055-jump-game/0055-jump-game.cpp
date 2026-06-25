class Solution {
public:
    bool solve(int idx, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();

        if (idx >= n - 1) return true;

        if (dp[idx] != -1)
            return dp[idx];

        for (int jump = 1; jump <= nums[idx]; jump++) {
            if (solve(idx + jump, nums, dp))
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};