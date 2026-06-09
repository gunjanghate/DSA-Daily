class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
      return (long long)(mx - mn) * k;

    }
};