class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        sort(nums.rbegin(), nums.rend());
        vector<int> results;

        int i = 0;
        while (k > 0 && i < nums.size()) {
            results.push_back(nums[i]);
            int curr = nums[i];

            while (i < nums.size() && nums[i] == curr) {
                i++;
            }

            k--;
        }

        return results;
    }
};
