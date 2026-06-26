class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newI) {
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();

        while (i < n && intervals[i][1] < newI[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newI[1]) {
            newI[0] = min(newI[0], intervals[i][0]);
            newI[1] = max(newI[1], intervals[i][1]);
            i++;
        }

        ans.push_back(newI);

        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};