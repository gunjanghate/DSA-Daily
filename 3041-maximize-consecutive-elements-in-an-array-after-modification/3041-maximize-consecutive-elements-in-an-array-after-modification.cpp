class Solution {
public:
    int find(vector<int>& nums, int start, int target){
        int j = lower_bound(begin(nums)+start, end(nums), target) - begin(nums);

        if(j<nums.size() && nums[j] == target) return j;
        return -1;
    }
    int solve(int i, int inc, vector<int>& nums, vector<vector<int>> & dp){

        int currVal = nums[i] + inc; // inc 0 or 1

        if(dp[i][inc]!=-1) return dp[i][inc];

        int len = 1;
        // find currVal + 1 
        int j = find(nums, i+1, currVal+1);
        if(j!=-1){
            len = max(len, 1+solve(j, 0, nums, dp));
        }
        // find 
        // find currVal and then inc
        j = find(nums, i+1, currVal);
        if(j!=-1){
            len = max(len, 1+solve(j, 1, nums, dp));
        }
        

        return dp[i][inc] = len;
    }
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();

        int res = 1;
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        sort(begin(nums), end(nums));

        // 1 1 1 2 5

        for(int i = 0; i<n; i++){
            res = max({res, solve(i, 1, nums, dp), solve(i, 0, nums, dp)});
        }

        return res;
    }
};