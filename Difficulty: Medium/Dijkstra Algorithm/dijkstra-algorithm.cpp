#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);

        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); 
        }

        // Min-heap storing {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue;

            for (auto &edge : adj[node]) {
                int adjNode = edge.first;
                int edgewt = edge.second;

                if (dis + edgewt < dist[adjNode]) {
                    dist[adjNode] = dis + edgewt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};