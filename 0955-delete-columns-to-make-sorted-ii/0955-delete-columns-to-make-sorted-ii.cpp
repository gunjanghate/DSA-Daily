class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();

        vector<bool> sorted(m - 1, false);
        int deletions = 0;

        for (int col = 0; col < n; col++) {
            bool bad = false;

            // check column
            for (int row = 0; row < m - 1; row++) {
                if (!sorted[row] && strs[row][col] > strs[row + 1][col]) {
                    bad = true;
                    break;
                }
            }

            // if bad column → delete
            if (bad) {
                deletions++;
                continue;
            }

            // update sorted status
            for (int row = 0; row < m - 1; row++) {
                if (!sorted[row] && strs[row][col] < strs[row + 1][col]) {
                    sorted[row] = true;
                }
            }
        }

        return deletions;
    }
};
