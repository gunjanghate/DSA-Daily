class Solution {
public:
    int candy(vector<int>& ratings) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = ratings.size();
        int cnt = 0;
        vector<int> candy(n, 1);
        for (int i = 1; i < n; i++)
            if (ratings[i] > ratings[i - 1])
                candy[i] = candy[i - 1]+1;

        for (int i = n - 1; i > 0; i--) {
            if (ratings[i] < ratings[i - 1])
                candy[i - 1] = max(candy[i - 1], candy[i] + 1);
            cnt += candy[i - 1];
        }

        return cnt + candy[n - 1];
    }
};