class Solution {
public:
    bool satisfy(vector<vector<int>>& mat, int row, int col, int n, int m){
        // row wise
        for(int i = 0; i<n; i++){
            if(i==row) continue;
            if(mat[i][col] == 1) return false;
        }
        // col wise
        for(int i = 0; i<m; i++){
            if(i==col) continue;
            if(mat[row][i] == 1) return false;
        }


        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt  = 0;
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(mat[i][j]==1){
                    if(satisfy(mat, i, j, n, m)) cnt++;
                }
            }
        }

        return cnt;
    }
};