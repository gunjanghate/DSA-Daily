class Solution {
public:
    int dfs(int i, int j, int m, vector<vector<int>>& t, vector<vector<int>>& dp){
        if(i==m-1) return t[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int down = t[i][j] + dfs(i+1, j, m, t, dp);
        int diagonal = t[i][j] + dfs(i+1, j+1, m, t, dp);

        return dp[i][j] = min(down , diagonal);
    }
    int minimumTotal(vector<vector<int>>& t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int m = t.size();

        vector<vector<int>> dp(m);
        for(int i = 0; i<m; i++){
            dp[i] = vector<int>(t[i].size(),-1);
        }
        dp[0][0] = t[0][0];
        vector<int> prev(t[0].size(),t[0][0]);

        for(int i = 1; i<m; i++){
            vector<int> curr(t[i].size(), 0);
            for(int j = 0; j<t[i].size(); j++){
                if(i==0 && j==0){
                    continue;
                }
                else if(j==0){
                    curr[j] = t[i][j] + prev[j];
                }
                else if(j==i){
                    curr[j] = t[i][j] + prev[j-1]; 

                } else{
                int up = t[i][j] + prev[j]; 

                int diagonal = t[i][j] + prev[j-1];

                curr[j] = min(up, diagonal);
                }
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};