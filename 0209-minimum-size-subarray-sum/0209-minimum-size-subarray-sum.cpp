class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        int l = 0, r = 0;
        int minL = INT_MAX;
        int sum = nums[0];
        while (l <= r && r < n) {

            if (sum < target) {
                r++;
                if (r == n)
                    break;
                sum += nums[r];
            }

            if (sum >= target) {
                minL = min(minL, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        if (minL == INT_MAX)
            return 0;
        return minL;
    }
};