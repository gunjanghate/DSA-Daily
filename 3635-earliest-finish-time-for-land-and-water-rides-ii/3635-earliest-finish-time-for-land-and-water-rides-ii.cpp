class Solution {
public:
    int calc(vector<int>& start1, vector<int>& dur1,
             vector<int>& start2, vector<int>& dur2) {

        int minEnd = INT_MAX;

        // Earliest finish time of first category
        for (int i = 0; i < start1.size(); i++) {
            minEnd = min(minEnd, start1[i] + dur1[i]);
        }

        int ans = INT_MAX;

        // Earliest finish time after taking second category
        for (int i = 0; i < start2.size(); i++) {
            ans = min(ans,
                      max(minEnd, start2[i]) + dur2[i]);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& ls, vector<int>& ld,
                           vector<int>& ws, vector<int>& wd) {

        int landFirst = calc(ls, ld, ws, wd);
        int waterFirst = calc(ws, wd, ls, ld);

        return min(landFirst, waterFirst);
    }
};