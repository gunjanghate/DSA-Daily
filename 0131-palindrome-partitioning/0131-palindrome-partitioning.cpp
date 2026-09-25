class Solution {
public:

    void solve(string &s, int index, vector<string>& str,
               vector<vector<string>>& ans,
               vector<vector<bool>>& palindrome) {

        if (index == s.size()) {
            ans.push_back(str);
            return;
        }

        for (int i = index; i < s.size(); i++) {

            if (palindrome[index][i]) {

                string curr = s.substr(index, i - index + 1);

                str.push_back(curr);

                solve(s, i + 1, str, ans, palindrome);

                str.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        int n = s.length();

        vector<vector<bool>> palindrome(
            n, vector<bool>(n, false)
        );

        for (int i = 0; i < n; i++) {
            palindrome[i][i] = true;
        }

        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len <= n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j] &&
                    (len == 2 || palindrome[i + 1][j - 1])) {

                    palindrome[i][j] = true;
                }
            }
        }

        vector<string> str;
        vector<vector<string>> ans;

        solve(s, 0, str, ans, palindrome);

        return ans;
    }
};