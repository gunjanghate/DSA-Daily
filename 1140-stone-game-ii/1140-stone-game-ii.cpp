class Solution {
public:
    int solve(int i, int m, vector<int>& suffix,vector<vector<int>>& dp){
        if(i>=suffix.size()-1) return 0;

        if(dp[i][m] != -1) return dp[i][m];
        int ans = 0;

        for(int x = 1; x <= 2*m && x + i<=suffix.size()-1; x++){
            ans = max(ans, suffix[i] -  solve(i+x, max(m,x), suffix, dp));
        }

        return dp[i][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        vector<int> suffix(n+1, 0);
        for(int i = n-1; i >=0; i--){
            suffix[i] += suffix[i+1] + piles[i];
        }

        return solve(0, 1, suffix, dp);  
    }
};