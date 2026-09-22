class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {

        vector<vector<pair<int, int>>> adj(V + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> d1(V + 1, INT_MAX);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        d1[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > d1[node])
                continue;

            for (auto a : adj[node]) {

                int adjNode = a.first;
                int wt = a.second;

                if (dis + wt < d1[adjNode]) {
                    d1[adjNode] = dis + wt;
                    pq.push({d1[adjNode], adjNode});
                }
            }
        }

        if (d1[dest] == INT_MAX)
            return {-1};


        vector<int> d2(V + 1, INT_MAX);

        pq.push({0, dest});
        d2[dest] = 0;

        while (!pq.empty()) {

            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > d2[node])
                continue;

            for (auto a : adj[node]) {

                int adjNode = a.first;
                int wt = a.second;

                if (dis + wt < d2[adjNode]) {
                    d2[adjNode] = dis + wt;
                    pq.push({d2[adjNode], adjNode});
                }
            }
        }

        vector<int> ans;

        int node = src;
        ans.push_back(node);

        while (node != dest) {

            int nextNode = INT_MAX;

            for (auto a : adj[node]) {

                int adjNode = a.first;
                int wt = a.second;

                // wt of src to prev of curr node + curr node + dest to curr node
                if (d1[node] + wt + d2[adjNode] == d1[dest]) {

                    nextNode = min(nextNode, adjNode);
                }
            }

            node = nextNode;
            ans.push_back(node);
        }

        return ans;
    }
};