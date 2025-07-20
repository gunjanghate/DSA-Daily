class Solution {
    public:
    void solve(string ans,  vector<string> &ll, int open, int close, int n){
            if(ans.length()==2*n) {
			ll.push_back(ans);
			return;
            }
            if(open<n) solve(ans+"(", ll, open+1, close, n);
            if(open>close) solve(ans+")", ll, open, close+1, n);
	}

    vector<string> generateParenthesis(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string> ll;
        solve("", ll, 0, 0, n);
        return ll;

    }
};