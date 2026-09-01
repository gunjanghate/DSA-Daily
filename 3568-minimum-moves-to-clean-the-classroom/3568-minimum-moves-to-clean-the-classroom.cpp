class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();
        int maxEnergy = energy;

        vector<vector<int>> litterId(n, vector<int>(m, -1));

        int sr = -1, sc = -1;
        int totalLitter = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') { sr = i; sc = j; }
                if (classroom[i][j] == 'L') litterId[i][j] = totalLitter++;
            }
        }

        if (totalLitter == 0)
            return 0;

        int fullMask = (1 << totalLitter) - 1;

        // dist[r][c][energy][mask] = min moves to reach this state, or -1 if unvisited
        vector<vector<vector<vector<int>>>> dist(
            n, vector<vector<vector<int>>>(
                m, vector<vector<int>>(
                    energy + 1, vector<int>(1 << totalLitter, -1)
                )
            )
        );

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        queue<tuple<int,int,int,int>> q;

        int startMask = 0; 
        dist[sr][sc][energy][startMask] = 0;
        q.push({sr, sc, energy, startMask});

        while (!q.empty()) {
            auto [r, c, e, mask] = q.front();
            q.pop();
            int curDist = dist[r][c][e][mask];

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (classroom[nr][nc] == 'X') continue;
                if (e == 0) continue; 

                int newEnergy = e - 1;
                int newMask = mask;

                if (classroom[nr][nc] == 'L') {
                    newMask |= (1 << litterId[nr][nc]); // eg, 1 << 1 = 10   
                // If litter #1 was already collected (newMask = 010) and we now collect litter #0, 010 | 001 = 011
                }
                if (classroom[nr][nc] == 'R') {
                    newEnergy = maxEnergy;
                }

                if (dist[nr][nc][newEnergy][newMask] != -1)
                    continue;

                dist[nr][nc][newEnergy][newMask] = curDist + 1;

                if (newMask == fullMask)
                    return curDist + 1;

                q.push({nr, nc, newEnergy, newMask});
            }
        }

        return -1; 
    }
};