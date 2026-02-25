class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, vector<int>> mp;
        vector<int> ans;
        for (auto i : arr) {
            mp[__builtin_popcount(i)].push_back(i);
        }

        for (auto m : mp) {
            sort(m.second.begin(), m.second.end());
            for (int i = 0; i < m.second.size(); i++) {
                ans.push_back(m.second[i]);
            }
        }

        return ans;
    }
};