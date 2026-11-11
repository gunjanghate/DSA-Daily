class Solution {
public:

    long long solve(int x, int y, int cost1, int cost2, int costBoth, int need1, int need2, vector<vector<long long>>& dp){

        if(x>=need1 && y>=need2) return 0;
        
        // if(x > need1 || y > need2) return 1e18;


        if(dp[x][y]!=-1) return dp[x][y];


        // type 1
        long long t1 = cost1 + solve(x+1, y, cost1, cost2, costBoth, need1, need2, dp);
        // type 2
        long long t2 = cost2 + solve(x, y+1, cost1, cost2, costBoth, need1, need2, dp);
        // type 3
        long long t3 = costBoth + solve(x+1, y+1, cost1, cost2, costBoth, need1, need2, dp);

        return dp[x][y] = min({t1, t2, t3});
        
    }
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        // vector<vector<long long>> dp(need1 + 1, vector<long long>(need2 + 1, -1));
        // return solve(0, 0, cost1, cost2, costBoth, need1, need2, dp);



        long long mn = min(need1, need2);
        long long mx = max(need1, need2);

        long long ans = mn * min(1LL * costBoth,
                                 1LL * cost1 + cost2);

        if(need1 > need2) {
            ans += (mx - mn) * min(1LL * cost1, 1LL * costBoth);
        }
        else {
            ans += (mx - mn) * min(1LL * cost2, 1LL * costBoth);
        }

        return ans;
    }
};
