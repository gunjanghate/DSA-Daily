class Solution {
public:
    int minimumDeletions(string word, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<char, int> mp;
        int dlt = 0;
        int minDelete = INT_MAX;
        for (auto i : word)
            mp[i]++;
        vector<pair<char, int>> freqVec(mp.begin(), mp.end());

        sort(freqVec.begin(), freqVec.end(),
             [](auto& a, auto& b) { return a.second < b.second; });

        for (int i = 0; i < freqVec.size(); i++) {
            int x = freqVec[i].second;
            for (int j = 0; j < freqVec.size(); j++) {
                if (freqVec[i].first == freqVec[j].first)
                    continue;
                int y = freqVec[j].second;
                // y - x <= k
                // y <= k + x
                // if-> y > k + x
                // dlt = y - (k + x)
                if (y < x) {
                    dlt += y;
                } else if (y > x + k) {
                    dlt += (y - x - k);
                }
            }
            minDelete = min(minDelete, dlt);
            dlt = 0;
        }

        return minDelete;
    }
};