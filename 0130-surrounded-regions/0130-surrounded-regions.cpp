class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &b, int dr[], int dc[] ){
        vis[row][col] = 1;

        for(int i =0; i<4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr >= 0 && nr < b.size() && nc >=0 && nc <b[0].size() && !vis[nr][nc] && b[nr][nc]=='O'){
                dfs(nr, nc, vis, b, dr, dc);
            }

        }
        
    }
public:
    void solve(vector<vector<char>>& b) {
        int n = b.size();
        int m = b[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m,0));
        // traverse first row and last row
        for(int j = 0; j<m; j++){
            if(!vis[0][j] && b[0][j] == 'O'){
                dfs(0,j,vis,b, dr, dc);
            }
            if(!vis[n-1][j] && b[n-1][j] == 'O'){

                dfs(n-1,j,vis,b, dr,dc);
            }
        }
        // traverse first col and last col
        for(int i = 0; i<n; i++){
            if(!vis[i][0] && b[i][0] == 'O'){
                dfs(i,0,vis,b, dr, dc);
            }
            if(!vis[i][m-1] && b[i][m-1] == 'O'){

                dfs(i,m-1,vis,b, dr,dc);
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                if(b[i][j]=='O' && !vis[i][j]){
                    b[i][j] = 'X';
                }
            }
        }



    }
};