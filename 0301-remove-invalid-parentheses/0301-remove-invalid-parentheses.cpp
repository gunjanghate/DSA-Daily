class Solution {
public:
    void solve(int i, string& s, string& curr, int b, int n,
               unordered_set<string>& st, int& maxLen) {

        if (b < 0)
            return;

        if (i == n) {

            if (b == 0) {

                if (curr.length() > maxLen) {
                    st.clear();
                    maxLen = curr.length();
                }

                if (curr.length() == maxLen) {
                    st.insert(curr);
                }
            }

            return;
        }

        if (s[i] != '(' && s[i] != ')') {

            curr.push_back(s[i]);

            solve(i + 1, s, curr, b, n, st, maxLen);

            curr.pop_back();

            return;
        }


        curr.push_back(s[i]);

        if (s[i] == '(')
            solve(i + 1, s, curr, b + 1, n, st, maxLen);
        else
            solve(i + 1, s, curr, b - 1, n, st, maxLen);

        curr.pop_back();


        solve(i + 1, s, curr, b, n, st, maxLen);
    }

    vector<string> removeInvalidParentheses(string s) {

        int n = s.length();

        unordered_set<string> st;

        int maxLen = 0;

        string curr = "";

        solve(0, s, curr, 0, n, st, maxLen);

        return vector<string>(st.begin(), st.end());
    }
};