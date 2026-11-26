class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            __int128 prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {
                prod *= nums[j];

                g = gcd(g, (long long)nums[j]);
                l = l / gcd(l, (long long)nums[j]) * nums[j];

                __int128 target = (__int128)g * l;

                if (prod == target) {
                    ans = max(ans, j - i + 1);
                }

                if (prod > target) {
                    break;
                }
            }
        }

        return ans;
    }
};