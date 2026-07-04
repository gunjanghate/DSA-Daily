class Solution {

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> best(n, vector<int>(m, -1));
        vector<pair<int, int>> dr = {{1, 0}, {-1, 0}, {0,1}, {0, -1}};
    
        queue<vector<int>> q;
        int sH = health - grid[0][0];
        if(sH<1) return false;
        q.push({0,0, sH});
        best[0][0] = sH;

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr[0];
            int j = curr[1];
            int h = curr[2];
            if(i==n-1 && j==m-1) return true; 

            for(auto [dx, dy] : dr){
                int nx = i + dx;
                int ny = j + dy;

                if(nx < 0 ||  ny >= m || nx >= n || ny < 0) continue;

                int nH = h - grid[nx][ny];
                if(nH<1) continue;
                if(best[nx][ny]>=nH) continue;

                q.push({nx, ny, nH});
                best[nx][ny] = nH;
            }


        }

    return false;    

    }
};