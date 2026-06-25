class Solution {
public:

    int solve(int idx,
              vector<int>& nums,
              vector<int>& dp) {

        int n = nums.size();

        if (idx >= n - 1)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int ans = 1e9;

        for (int jump = 1; jump <= nums[idx]; jump++) {
            ans = min(ans,
                     1 + solve(idx + jump,
                               nums,
                               dp));
        }

        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);

        return solve(0, nums, dp);
    }
};