class Solution {
public:
    int solve(int i, int n, vector<int>& nums, int prev, vector<vector<int>>& dp){
        if(i>=n) return 0;

        if(dp[i][prev+1]!=-1)  return dp[i][prev+1];

        int len = solve(i+1, n, nums, prev, dp);

        if(prev==-1 || (nums[prev] < nums[i])){
          len = max(len, 1 + solve(i+1, n, nums, i, dp));
        }

        return dp[i][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // return solve(0, n, nums, -1, dp);

        // vector<int> nextar(n+1, 0), curr(n+1, 0);

        // for(int i = n-1; i>=0; i--){
        //     for(int prev = i - 1; prev >= -1; prev--){
        //         int len = nextar[prev+1];

        //         if(prev==-1 || (nums[prev] < nums[i])){
        //         len = max(len, 1 + nextar[i+1]);
        //         }    

        //         curr[prev+1] = len;            
        //     }

        //     nextar = curr;
        // }


        // return curr[-1+1];

        vector<int> dp(n, 1);

        for(int i = 0; i<n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i])
                    dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }


        return *max_element(dp.begin(), dp.end());


    }
};