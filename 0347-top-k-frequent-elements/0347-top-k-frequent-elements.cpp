class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<int, int> freq;
        for (auto n : nums) freq[n]++;

        vector<int> sortedFreq;
        for (auto &p : freq) sortedFreq.push_back(p.second);
        sort(sortedFreq.begin(), sortedFreq.end(), greater<int>());

        vector<int> kfreqs(sortedFreq.begin(), sortedFreq.begin() + k);

        vector<int> ans;
        for (auto &p : freq) {
            if (find(kfreqs.begin(), kfreqs.end(), p.second) != kfreqs.end()) {
                ans.push_back(p.first);
                kfreqs.erase(find(kfreqs.begin(), kfreqs.end(), p.second));
                if (ans.size() == k) break;
            }
        }
        return ans;
    }
};
