class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 3, 0);

        for (int i = n - 1; i >= 0; i--) {
            int sum = 0;
            dp[i] = INT_MIN;

            for(int take = 0; take < 3 && i + take < n; take++){
                sum += nums[i+ take];
                dp[i] = max(dp[i], sum - dp[i+take+1]);
            }
        }

        if(dp[0]>0) return "Alice";
        if(dp[0]<0) return "Bob";
        return "Tie";
    }
};