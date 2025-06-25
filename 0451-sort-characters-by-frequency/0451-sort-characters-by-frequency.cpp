class Solution {
public:
    string frequencySort(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<char, int> mp;
        int n = s.length();

        for (char c : s) {
            mp[c]++;
        }

        vector<vector<char>> buckets(n + 1);
        for (auto [ch, freq] : mp) {
            buckets[freq].push_back(ch);
        }

        string ans = "";
        for (int i = n; i >= 1; i--) {
            for (char ch : buckets[i]) {
                ans.append(i, ch); 
            }
        }

        return ans;
    }
};
