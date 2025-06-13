class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = mat.size();
        int m = mat[0].size();

        int l = 0, h = m - 1;
        int row;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int mx = INT_MIN;
            int r = -1 , c = -1;
            for (int i = 0; i < n; i++) {
                if(mx<mat[i][mid]){
                mx = max(mx, mat[i][mid]);
                r = i; c = mid;
                }
            } // finding position of max element in column
            int left = mid-1>=0? mat[r][mid-1]:-1;
            int right = mid+1<m? mat[r][mid+1]:-1;
            if (mat[r][mid]>right && mat[r][mid]>left) {
                return {r, mid};
            } else if(mat[r][mid]<left){
                h = mid-1;
            }else if(mat[r][mid]<right) l = mid+1;
        }
        return {-1, -1};
    }
};