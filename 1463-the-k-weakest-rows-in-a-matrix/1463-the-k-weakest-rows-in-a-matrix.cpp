class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = mat.size();
        int n = mat[0].size();
        int cnt;
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++) {
            cnt = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    cnt++;
            }
            mp[i] = cnt;
        }
        vector<pair<int, int>> sortedRows(mp.begin(), mp.end());
        sort(sortedRows.begin(), sortedRows.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.second == b.second)
                     return a.first < b.first;
                 return a.second < b.second;
             });
        vector<int> ans;
        for (auto& [row, count] : sortedRows) {
            if (k > 0) {
                ans.push_back(row);
                k--;
            } else
                break;
        }
        return ans;
    }
};