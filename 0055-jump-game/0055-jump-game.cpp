class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIdx = n - 1;
        vector<bool> dp(n, false);


        for(int i = n -1; i>=0; i--){
            if(i + nums[i] >= n-1) {
                dp[i] = true;
                maxIdx = i;
            }
            if(maxIdx <= i + nums[i]){
                dp[i] = true;
                maxIdx = i;
            }
        }

        return dp[0];

    }
};