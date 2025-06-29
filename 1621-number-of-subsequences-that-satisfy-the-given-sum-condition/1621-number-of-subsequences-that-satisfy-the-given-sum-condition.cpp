class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        const int MOD = 1e9 + 7;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2LL) % MOD;
        }

        int i = 0, j = n - 1, res = 0;
        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                res = (res + pow2[j - i]) % MOD;
                i++;
            } else {
                j--;
            }
        }

        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
