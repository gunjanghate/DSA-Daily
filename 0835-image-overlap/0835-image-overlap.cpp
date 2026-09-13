class Solution {
public:
    int countOverlaps(vector<vector<int>>& a, vector<vector<int>>& b, int i,
                      int j) {
        int n = a.size();

        int cnt = 0;

        for (int l = 0; l < n; l++) {
            for (int m = 0; m < n; m++) {
                int b_i = l + i;
                int b_j = m + j;
                if (b_i >= 0 && b_j >= 0 && b_i < n && b_j < n) {

                    if (a[l][m] == 1 && b[b_i][b_j] == 1)
                        cnt++;
                }
            }
        }

        return cnt;
    }

    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();

        int mx = 0;

        for (int i = -n + 1; i < n; i++) {
            for (int j = -n + 1; j < n; j++) {
                int cnt = countOverlaps(a, b, i, j);

                mx = max(mx, cnt);
            }
        }

        return mx;
    }
};