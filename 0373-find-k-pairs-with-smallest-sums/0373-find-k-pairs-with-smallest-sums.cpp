class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                       vector<int>& nums2,
                                       int k) {

        vector<vector<int>> ans;

        if(nums1.empty() || nums2.empty() || k == 0)
            return ans;

        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        for(int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while(k-- && !pq.empty()) {

            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            if(j + 1 < nums2.size()) {
                pq.push({
                    nums1[i] + nums2[j + 1],
                    i,
                    j + 1
                });
            }
        }

        return ans;
    }
};