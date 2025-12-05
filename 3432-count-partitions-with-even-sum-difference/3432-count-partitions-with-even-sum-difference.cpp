class Solution {
public:
    int countPartitions(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // int n = nums.size();
        // int ans = 0;
        // for (int i = 1; i < n; i++) {
        //     int sum = abs(accumulate(nums.begin(), nums.begin() + i, 0) -
        //                   accumulate(nums.begin() + i, nums.end(), 0));
        //     if (sum % 2 == 0)
        //         ans++;
        // }
        // return ans;
        int n = nums.size();
        int ans = 0;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for (int i = 0; i < n - 1; i++) { 
            leftSum += nums[i];
            int rightSum = totalSum - leftSum;
            if (abs(leftSum - rightSum) % 2 == 0)
                ans++;
        }
        return ans;
    }
};