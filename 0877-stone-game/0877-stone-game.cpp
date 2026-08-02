class Solution {
public:
// "If I take the left pile now, I gain piles[l], but then the opponent will play optimally and obtain an advantage of dp[l+1][r] over me. So my net advantage from choosing left is piles[l] - dp[l+1][r]."
    int solve(int l, int r, vector<int>& piles, vector<vector<int>>& dp){
        if(l==r) return piles[l];

        if(dp[l][r] != -1) 
            return dp[l][r];

        return dp[l][r] = max(
            piles[l] - solve(l+1, r, piles, dp),
            piles[r] - solve(l, r-1, piles, dp)
        );
    }
    bool stoneGame(vector<int>& piles) {
       int n = piles.size();
       vector<vector<int>> dp(n, vector<int>(n, -1));

       return solve(0, n-1, piles, dp) > 0;
    }
};