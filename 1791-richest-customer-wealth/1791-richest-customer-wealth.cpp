class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx = INT_MIN;
        for(int i = 0 ; i<accounts.size(); i++){
            int sum = accumulate(accounts[i].begin(), accounts[i].end(), 0);
            mx = max(mx, sum);
        }

        return mx;
    }
};