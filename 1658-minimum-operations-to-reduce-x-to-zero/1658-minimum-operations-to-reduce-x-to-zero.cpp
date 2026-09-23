class Solution {
public:
    // int solve(int i, int j, vector<int>& nums, int x,
    //           vector<vector<unordered_map<int, int>>>& dp) {

    //     if (i > j)
    //         return (x == 0) ? 0 : 1e9;

    //     if (x == 0)
    //         return 0;

    //     if (nums[i] > x && nums[j] > x)
    //         return 1e9;

    //     if (dp[i][j].count(x))
    //         return dp[i][j][x];

    //     int left = 1e9;
    //     int right = 1e9;

    //     if (nums[i] <= x) {
    //         left = 1 + solve(i + 1, j, nums, x - nums[i], dp);
    //     }

    //     if (nums[j] <= x) {
    //         right = 1 + solve(i, j - 1, nums, x - nums[j], dp);
    //     }

    //     return dp[i][j][x] = min(left, right);
    // }

    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        // vector<vector<unordered_map<int, int>>> dp(
        //     n, vector<unordered_map<int, int>>(n));

        // int ans = solve(0, n - 1, nums, x, dp);

        // if (ans >= 1e9)
        //     return -1;

        // return ans;

        unordered_map<int, int> mp;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mp[sum] = i;
        }

        mp[0] = -1;

        if(sum < x) return -1;

        int l = INT_MIN;
        int rem = sum - x;
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int find = sum - rem;
            if (mp.find(find) != mp.end()) {
                int idx = mp[find];
                l = max(l, i - idx);
            }
        }

        return l == INT_MIN ? -1 : n - l;
    }
};