class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        int top = 0;
        int down = n - 1;

        while (top < down) {
            if (mat[top][down] == 1) {
                top++;
            } else {
                down--;
            }
        }

        int cand = top;

        for (int i = 0; i < n; i++) {
            if (i == cand) continue;
            if (mat[i][cand] == 0 || mat[cand][i] == 1) {
                return -1;
            }
        }

        return cand;
    }
};