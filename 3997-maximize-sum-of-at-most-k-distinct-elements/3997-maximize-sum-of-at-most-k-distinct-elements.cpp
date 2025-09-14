class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        set<int> s(nums.begin(), nums.end());
        vector<int> distinct(s.begin(), s.end());
        sort(distinct.rbegin(), distinct.rend());

        vector<int> result;
        for (int i = 0; i < k && i < distinct.size(); i++) {
            result.push_back(distinct[i]);
        }

        return result;
    }
};
