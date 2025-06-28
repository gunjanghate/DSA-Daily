class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<pair<int, int>> val_idx;
        for (int i = 0; i < nums.size(); i++) {
            val_idx.push_back({nums[i], i});
        }

        sort(val_idx.begin(), val_idx.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        val_idx.resize(k);

        sort(val_idx.begin(), val_idx.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<int> ans;
        for (auto &p : val_idx) ans.push_back(p.first);

        return ans;
    }
};
