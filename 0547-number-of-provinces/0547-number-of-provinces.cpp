class Solution {
private:
    // void dfs(int i, vector<vector<int>>& isConnected, vector<int>& vis) {
    //     vis[i] = 1;
    //     for (int j = 0; j < isConnected[i].size(); j++) {
    //         if ((isConnected[i][j] == 1) && !vis[j])
    //             dfs(j, isConnected, vis);
    //     }
    // }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        // vector<vector<int>> adjList(V);

        // for(int i = 0; i < V; i++){
        //     for(int j = 0; j < V; j++){
        //         if(isConnected[i][j] == 1 && i != j){
        //             adjList[i].push_back(j);
        //         }
        //     }
        // }

        vector<int> vis(V + 1, 0);
        int cnt = 0;

        // for(int i = 0; i < V; i++){
        //     if(!vis[i]){
        //         cnt++;
        //         dfs(i, isConnected, vis);
        //     }
        // }

        for (int i = 0; i < V; i++) {

            if (!vis[i]) {
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                cnt++;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v = 0; v < V; v++) {

                        if (isConnected[u][v] == 1 && !vis[v]) {
                            vis[v] = 1;
                            q.push(v);
                        }
                    }
                }
            }
        }

        return cnt;
    }
};