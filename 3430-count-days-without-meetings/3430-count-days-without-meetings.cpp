class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> merged;
        merged.push_back(meetings[0]);
        for (int i = 1; i < meetings.size(); i++) {
            if (meetings[i][0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], meetings[i][1]);
            } else {
                merged.push_back(meetings[i]);
            }
        }
        int cnt = merged[0][0] - 1;
        for (int i = 0; i < merged.size() - 1; i++) {
            cnt += merged[i+1][0] - merged[i][1] - 1;
        }
        cnt += days - merged.back()[1];
        return cnt;
    }
};
