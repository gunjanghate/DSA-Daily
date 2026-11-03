class Solution {
public:
    long long findCost(vector<int>& nums, vector<int>& cost, int target) {
        long long ans = 0;
        int num = target;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            ans += (long long)cost[i] * (abs(nums[i] - num));
        }

        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // 1 3 5 2
        // 14 16 15 13

        int i = *min_element(nums.begin(), nums.end());
        int j = *max_element(nums.begin(), nums.end());

        int n = nums.size();
        long long ans = LLONG_MAX;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            long long c1 = findCost(nums, cost, mid);
            long long c2 = findCost(nums, cost, mid + 1);

            ans = min(ans, min(c1, c2));

            if (c2 > c1)
                j = mid - 1;
            else
                i = mid + 1;
        }

        return ans == LLONG_MAX ? 0 : ans;
    }
};