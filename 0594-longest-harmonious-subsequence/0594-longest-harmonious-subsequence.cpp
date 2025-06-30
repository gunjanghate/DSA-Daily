class Solution {
public:
    int findLHS(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        map<int, int> mp;
        for (auto i : nums)
            mp[i]++;
        if (mp.size() < 2)
            return 0;
        int cnt = 0, ans = 0;
        for (auto it = mp.begin(); next(it) != mp.end(); ++it) {
            auto next_it = next(it);
            if (abs(it->first - next_it->first) == 1) {
                cnt = it->second + next_it->second;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};