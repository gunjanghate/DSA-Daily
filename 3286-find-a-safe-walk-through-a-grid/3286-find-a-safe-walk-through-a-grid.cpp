class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> best(n, vector<int>(m, -1));

        queue<vector<int>> q;

        int startHealth = health - grid[0][0];

        if (startHealth < 1)
            return false;

        q.push({0, 0, startHealth});
        best[0][0] = startHealth;

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while (!q.empty()) {

            auto curr = q.front();
            q.pop();

            int i = curr[0];
            int j = curr[1];
            int h = curr[2];

            if (i == n - 1 && j == m - 1)
                return true;

            for (auto [dx, dy] : dir) {

                int ni = i + dx;
                int nj = j + dy;

                if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                    continue;

                int newHealth = h - grid[ni][nj];

                if (newHealth < 1)
                    continue;

                if (best[ni][nj] >= newHealth)
                    continue;

                best[ni][nj] = newHealth;
                q.push({ni, nj, newHealth});
            }
        }

        return false;
    }
};