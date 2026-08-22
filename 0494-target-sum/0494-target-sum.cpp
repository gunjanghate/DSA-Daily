class Solution {
public:
    int solve(int i, vector<int> &nums, int target, int n, int sum, vector<vector<int>>& dp, int ts){
        if(i==n){
            return sum==target;
        } 

        if(dp[i][sum + ts]!=-1) return dp[i][sum+ts];

        int minus = solve(i+1, nums, target, n, sum - nums[i], dp, ts);
        int plus = solve(i+1, nums, target, n, sum + nums[i], dp, ts);
        return dp[i][sum + ts] = minus + plus;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int ts = accumulate(nums.begin(), nums.end(), 0);

        if(ts < target || -ts > target) return 0;


        vector<vector<int>> dp(n+1, vector<int>(2*ts+1, 0));

        vector<int> prev(2*ts+1, 0);

        prev[ts] = 1; 

        for (int i = 1; i <= n; i++) {
        vector<int> curr(2*ts+1, 0);
            for (int s = -ts; s <= ts; s++) {

                int index = s + ts;

                
                if (s - nums[i - 1] >= -ts &&
                    s - nums[i - 1] <= ts) {

                    curr[index] +=
                        prev[s - nums[i - 1] + ts];
                }

                if (s + nums[i - 1] >= -ts &&
                    s + nums[i - 1] <= ts) {

                    curr[index] +=
                        prev[s + nums[i - 1] + ts];
                }
            }
            prev = curr;
        }

        return prev[target + ts];


        // return solve(0, nums, target, n, 0, dp, ts);
        
    }
};