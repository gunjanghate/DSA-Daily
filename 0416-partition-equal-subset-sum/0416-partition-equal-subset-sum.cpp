class Solution {
public:
    bool solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target==0){
            return true; 
        }
        if(i==0) return nums[0] == target;

        
        if(dp[i][target]!=-1) return dp[i][target];

        bool noTake = solve(i-1, target, nums, dp);

        bool take = false;
        if(nums[i]<=target){
            take = solve(i-1, target - nums[i], nums, dp);
        }        

        return dp[i][target] = noTake || take;
    }
    bool canPartition(vector<int>& nums) {
        int ts = accumulate(nums.begin(), nums.end(), 0);
        int s = ts/2;
        if(ts%2!=0) return false;
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(s+1, -1));

        return solve(n-1, s, nums , dp);
    }
};