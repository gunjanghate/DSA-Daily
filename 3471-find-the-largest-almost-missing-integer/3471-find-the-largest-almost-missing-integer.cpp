class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for (auto i : nums)
            mpp[i]++;

        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (k == n || mpp[nums[i]] == 1 && (k == 1 || i == 0 || i == n - 1)){

                ans = max(ans, nums[i]);
            }   
        }

        return ans;
    }
};