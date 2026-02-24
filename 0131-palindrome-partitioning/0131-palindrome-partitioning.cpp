class Solution {
public:
    bool isPalindrome(string s){
        string org = s;
        reverse(s.begin(), s.end());
        return org == s;
    }
    void solve(string s, vector<string>& str,
               vector<vector<string>>& ans) {
        // base case
        if (s.size() == 0) {
            ans.push_back(str);
            return;
        }
        // rec logic
        for (int i = 0; i < s.size(); i++) {
            string curr = s.substr(0, i+1);
            if(isPalindrome(curr)){
                str.push_back(curr);
                solve(s.substr(i + 1), str, ans);
                str.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> str;
        vector<vector<string>> ans;
        solve(s, str, ans);
        return ans;
    }
};