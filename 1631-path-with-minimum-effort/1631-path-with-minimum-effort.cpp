class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};

        int ans = INT_MAX;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r == n-1 && c == m-1){
                return diff;
            }



            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int newdiff = max(abs(h[r][c] - h[nr][nc]), diff);

                    if (newdiff < dist[nr][nc]) {

                        dist[nr][nc] = newdiff;
                        pq.push({newdiff, {nr, nc}});
                    }
                }
            }
        }

        return ans;
    }
};