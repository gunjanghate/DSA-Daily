class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            if (target >= matrix[i][0] && matrix[i][m-1]>=target) {
                if (binary_search(matrix[i].begin(), matrix[i].end(), target))
                    return true;
            }
        }

        return false;
    }
};