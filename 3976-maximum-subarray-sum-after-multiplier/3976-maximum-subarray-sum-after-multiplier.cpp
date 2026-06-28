class Solution {
public:
    long long kadane(vector<int>& nums, int k, bool multiply) {

        long long NEG = -4e18;

        long long dp0 = NEG; // operation not started
        long long dp1 = NEG; // operation in progress
        long long dp2 = NEG; // operation finished

        long long ans = NEG;

        for (int x : nums) {

            long long normal = x;
            long long changed;

            if (multiply)
                changed = 1LL * x * k;
            else
                changed = x / k;

            long long new0 = max(normal, dp0 + normal);

            long long new1 = max(changed, max(dp0 + changed, dp1 + changed));

            long long new2 = max(normal, max(dp1 + normal, dp2 + normal));

            dp0 = new0;
            dp1 = new1;
            dp2 = new2;

            ans = max(ans, max(dp0, max(dp1, dp2)));
        }

        return ans;
    }

    long long maxSubarraySum(vector<int>& nums, int k) {

        long long multiplyAns = kadane(nums, k, true);

        long long divideAns = kadane(nums, k, false);

        return max(multiplyAns, divideAns);
    }
};