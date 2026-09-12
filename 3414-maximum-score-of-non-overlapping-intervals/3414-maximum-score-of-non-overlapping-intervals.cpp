class Solution {
public:
    pair<long long, vector<int>>
    solve(int i, int k, vector<vector<int>>& a, vector<int>& nxt,
          vector<vector<pair<long long, vector<int>>>>& dp,
          vector<vector<bool>>& vis) {

        if (i >= a.size() || k == 4)
            return {0, {}};

        if (vis[i][k])
            return dp[i][k];

        vis[i][k] = true;

        auto notTake = solve(i + 1, k, a, nxt, dp, vis);

        auto take = solve(nxt[i], k + 1, a, nxt, dp, vis);

        take.first += a[i][2];
        take.second.push_back(a[i][3]);

        sort(take.second.begin(), take.second.end());

        if (take.first > notTake.first) {
            dp[i][k] = take;
        } else if (take.first < notTake.first) {
            dp[i][k] = notTake;
        } else {
            sort(notTake.second.begin(), notTake.second.end());

            if (take.second < notTake.second)
                dp[i][k] = take;
            else
                dp[i][k] = notTake;
        }

        return dp[i][k];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        vector<vector<int>> a;

        for (int i = 0; i < intervals.size(); i++) {
            a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }

        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            if (x[0] != y[0])
                return x[0] < y[0];

            return x[1] < y[1];
        });

        int n = a.size();

        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {

            nxt[i] = upper_bound(a.begin() + i + 1, a.end(), a[i][1],
                                 [](int endTime, const vector<int>& interval) {
                                     return endTime < interval[0];
                                 }) -
                     a.begin();
        }

        
        vector<vector<pair<long long, vector<int>>>> dp(
            n, vector<pair<long long, vector<int>>>(4));

        vector<vector<bool>> vis(n, vector<bool>(4, false));

        return solve(0, 0, a, nxt, dp, vis).second;
    }
};