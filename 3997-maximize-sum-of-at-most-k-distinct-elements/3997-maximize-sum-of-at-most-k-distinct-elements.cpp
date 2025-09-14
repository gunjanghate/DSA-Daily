class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        set<int> s(nums.begin(), nums.end());
        vector<int> distinct(s.begin(), s.end());

        vector<int> result;
        for (int i = distinct.size()-1; k>0 && i >= 0; i--, k--) {
            result.push_back(distinct[i]);
        }

        return result;
    }
};
