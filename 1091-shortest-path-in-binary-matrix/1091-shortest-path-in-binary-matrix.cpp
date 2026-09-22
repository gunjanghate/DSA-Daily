class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        pair<int, int> src = {0 , 0};
        pair<int, int> disti = {n-1 , n-1};

        if(grid[0][0] !=0 ) return -1;
        if(n==1 && m==1 && grid[0][0] == 0) return 1;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 1;
        q.push({1,src});

        int dr[] = {-1, 0, 1, 0, -1, -1, 1, 1};
        int dc[] = {0, 1, 0, -1, -1, 1, -1, 1};

        while(!q.empty()){
            auto it = q.front();
            int r = it.second.first;
            int c = it.second.second;
            int dis = it.first;
            q.pop();

            if(dist[r][c] < dis) continue;

            for(int i = 0; i<8; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];


                if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc]==0
                && dis + 1 < dist[nr][nc]){
                    dist[nr][nc] = 1 + dis;
                    if(nr == disti.first && nc == disti.second){
                        return dist[nr][nc];
                    }  
                    q.push({dist[nr][nc], {nr, nc}});
                }
            }
        }

        return -1;
    }
};