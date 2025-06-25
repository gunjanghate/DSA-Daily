class Solution {
public:
    string frequencySort(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        vector<pair<char, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        string ans = "";
        for (auto [ch, freq] : v) {
            ans.append(freq, ch);  
        }

        return ans;
    }
};