class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& visited, int& cnt){
        visited[i][j] = 1;
        cnt++;

        for(int r = 0; r< n; r++){
            if(grid[r][j]==1 && visited[r][j]==-1){
                dfs(r, j, n , m, grid, visited, cnt);
            }
        }
        for(int c = 0; c< m; c++){
            if(grid[i][c]==1 && visited[i][c]==-1){
                dfs(i, c, n , m, grid, visited, cnt);
            }
        }

    }
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<int> rows(n, 0);
        // vector<int> cols(m, 0);


        // int ans = 0;

        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<m; j++){
        //         if(grid[i][j]==1){
        //             if((rows[i] || cols[j])){
        //                 ans += 1;
        //                 rows[i]= 1;
        //                 cols[j] = 1;
        //             }else{
        //                 rows[i]= 1;
        //                 cols[j] = 1;
        //             }

        //         }
        //     }
        // }

        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(m, -1));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]==-1){
                    int cnt = 0;

                    dfs(i, j, n, m, grid, visited, cnt);

                    if(cnt>1) ans += cnt;

                }
            }
        }


        return ans;
    }
};