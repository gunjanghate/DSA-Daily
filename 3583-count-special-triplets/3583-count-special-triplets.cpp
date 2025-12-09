class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        const long long MOD = 1e9 + 7;

        unordered_map<int, long long> right, left;
        for (int x : nums) right[x]++;

        long long ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            int x = nums[j];
            right[x]--;   

            int target = x * 2;

            long long leftCount = left[target];
            long long rightCount = right[target];

            ans = (ans + (leftCount * rightCount) % MOD) % MOD;

            left[x]++;   
        }

        return ans % MOD;
    }
};
