class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> cols(m,0);
        vector<int> row(n,0);
        for(int i = 0; i<n; i++){
            for(int j= 0; j<m; j++){
                if(matrix[i][j]==0){
                    cols[j]=1;
                    row[i]=1;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j= 0; j<m; j++){
                if(cols[j] || row[i]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};