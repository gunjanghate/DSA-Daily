class Solution {
public:
    void dfs(int initColor, int r, int c, vector<vector<int>>& ans,
            int color, int dr[], int dc[]) {
    // void dfs(int initColor, int r, int c, vector<vector<int>>& ans,
    //          vector<vector<int>>& image, int color, int dr[], int dc[]) {
        ans[r][c] = color;
        int n = ans.size();
        int m = ans[0].size();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                ans[nr][nc] == initColor && ans[nr][nc] != color) {
                    // dfs(initColor, nr, nc, ans, image, color, dr, dc);
                    dfs(initColor, nr, nc, ans, color, dr, dc);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int initColor = image[sr][sc];
        vector<vector<int>> ans = image;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        dfs(initColor, sr, sc, ans, color, dr, dc);
    
        return ans;
    }
};