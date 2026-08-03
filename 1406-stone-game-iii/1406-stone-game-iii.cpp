class Solution {
public:
    int solve(int i,vector<int>& nums, vector<int>& dp){
        if(i>=nums.size()) return 0;

        if(dp[i]!=INT_MIN) return dp[i];
        int sum = 0;
        int ans = INT_MIN;
        for(int take = 0; take<3 && take + i < nums.size() ; take++){
            sum += nums[i+take];
            ans = max(ans, sum - solve(i+1+take, nums, dp));
        }

        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);

        int s = solve(0, nums, dp);

        if(s>0) return "Alice";
        if(s<0) return "Bob";
        return "Tie";
    }
};