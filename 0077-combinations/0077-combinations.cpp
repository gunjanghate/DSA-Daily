class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> res;
        vector<int> ans;
        solve(1, n, k, ans, res);
        return res;
    }

    void solve(int a, int n, int k, vector<int>& ans,
               vector<vector<int>>& res) {
        if (ans.size() == k) {
            res.push_back(ans);
            return;
        }
        for(int i = a; i<n+1; i++){
            ans.push_back(i);
            solve(i+1, n, k, ans, res);
            ans.pop_back();
        }
    }
};