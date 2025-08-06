class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<int,int> freq;
        for (int n : nums) freq[n]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for (auto &p : freq) {
            pq.push({p.second, p.first});
            if (pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
