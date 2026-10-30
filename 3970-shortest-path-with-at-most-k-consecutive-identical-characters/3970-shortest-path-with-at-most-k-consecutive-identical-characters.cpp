class Solution {
public:
    typedef tuple<int, int, int> T;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // dijkstra 
        unordered_map<int, vector<vector<int>>> adj;

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});

        }
        vector<vector<int>> res(n, vector<int> (k+1, INT_MAX));

        priority_queue<T, vector<T>, greater<T>> pq; // min heap
        // to go fron src node to src node with cnt = 1
        res[0][1] = 0;
        pq.push({0,0,1});

        while(!pq.empty()){
            auto [d, node, cnt] = pq.top();
            pq.pop();

            if(d > res[node][cnt]) continue;

            if(node == n-1) return d;

            for(auto &v : adj[node]){
                int adjNode = v[0];
                int adjWt = v[1];

                int newC = (labels[adjNode]== labels[node]) ? cnt + 1 : 1;
                if(newC > k) continue;

                int newDis = adjWt + d;
                if(newDis < res[adjNode][newC]){
                    res[adjNode][newC] = newDis;
                    pq.push({newDis, adjNode, newC});
                }


            }
        }

        return -1;


    }
};