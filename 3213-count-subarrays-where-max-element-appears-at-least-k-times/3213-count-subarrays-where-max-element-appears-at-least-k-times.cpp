class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int mx = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int cnt = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == mx) cnt++;

            while (cnt >= k) {
                ans += nums.size() - right;
                if (nums[left] == mx) cnt--;
                left++;
            }
        }

        return ans;
    }
};
