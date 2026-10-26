class Solution {
public:
    long long solve(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j]<=0)
            return 0;
        long long s = grid[i][j];
        grid[i][j] = 0;
        s += solve(grid, i, j - 1);

        s += solve(grid, i, j + 1);

        s += solve(grid, i - 1, j);

        s += solve(grid, i + 1, j);

        return s;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]>0) {

                    long long sum = solve(grid, i, j);
                    if (!(sum % k))
                        cnt++;
                }
            }
        }
        return cnt;
    }
};