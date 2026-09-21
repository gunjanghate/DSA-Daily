#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> dist(V, INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()){
            int node = pq.top().second; 
            int dis = pq.top().first;
            pq.pop();
            
            if(dist[node] <  dis) continue;
            
            for(auto a : adj[node]){
                int adjNode = a.first;
                int wt = a.second;
                
                if(dis + wt < dist[adjNode]){
                    
                
                dist[adjNode] = dis + wt;
                pq.push({dist[adjNode], adjNode});
                }
                
            }
            
            
        }
        
        
        return dist;
    }
};