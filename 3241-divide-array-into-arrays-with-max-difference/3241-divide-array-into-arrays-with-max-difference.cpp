class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        sort(nums.begin(), nums.end());  // O(n log n)

        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i += 3) {
            if (i + 2 >= nums.size() ||
                abs(nums[i] - nums[i + 1]) > k ||
                abs(nums[i] - nums[i + 2]) > k ||
                abs(nums[i + 1] - nums[i + 2]) > k) {
                return {};
            }
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }

        return ans;
    }
};