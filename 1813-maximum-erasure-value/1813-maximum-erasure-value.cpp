class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, int> mp;
        int sum = 0, ans = INT_MIN;
        int start = 0;

        for (int j = 0; j < nums.size(); j++) {
            // shrinking window
            while (mp.find(nums[j]) != mp.end()) {
                sum -= nums[start];
                mp.erase(nums[start]);
                start++;
            }
            // expanding window
            sum += nums[j];
            mp[nums[j]] = 1;
            ans = max(ans, sum);
        }

        return ans;
    }
};
