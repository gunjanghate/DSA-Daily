class Solution {
public:
    double distFromOrigin(pair<int, int> pt) {

        int x1 = pt.first;
        int x2 = pt.second;
        return sqrt((x1 * x1) + (x2 * x2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;

        for (auto i : points) {
            pq.push({distFromOrigin({i[0], i[1]}), {i[0], i[1]}});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        cout<<pq.top().first<<endl;

        vector<vector<int>> ans;

        while (!pq.empty()) {
            auto it = pq.top();
            ans.push_back({it.second.first, it.second.second});
            pq.pop();
        }

        return ans;
        // 41 , 61, 52
    }
};