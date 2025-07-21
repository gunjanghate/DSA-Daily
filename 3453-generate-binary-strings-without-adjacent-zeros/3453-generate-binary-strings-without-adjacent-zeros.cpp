class Solution {
public:
    void solve(vector<string> &ans, string curr, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (curr.length() == n) {
            ans.push_back(curr);
            return;
        }
        solve(ans, curr + "1", n);

        if (curr.empty() || curr.back() != '0') {
            solve(ans, curr + "0", n);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        solve(ans, "", n);
        return ans;
    }
};
