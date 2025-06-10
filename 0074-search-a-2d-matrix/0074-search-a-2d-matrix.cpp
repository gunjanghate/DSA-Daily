class Solution {
public:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     int n = matrix.size();
    //     int m = matrix[0].size();
    //     for (int i = 0; i < n; i++) {
    //         if (target >= matrix[i][0] && matrix[i][m-1]>=target) {
    //             if (binary_search(matrix[i].begin(), matrix[i].end(), target))
    //                 return true;
    //         }
    //     }

    //     return false;
    // }// O(N) + O(LogN)
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = n*m - 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            //  | 0 1 2 3
            //0 | 0 1 2 3
            //1 | 4 5 6 7
            //2 | 8 9 10 11
            int rw = mid/m;
            int cl = mid%m;
            if(matrix[rw][cl]==target) return true;
            if(matrix[rw][cl]>target) high = mid-1;
            else low = mid+1;
        }

        return false;
    }
};