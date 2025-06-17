class Solution {
public:
    string removeOuterParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string ans;
        stack<char> st;
        int sz = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '(') {
                if (sz == 0) {
                    st.push(s[i]);
                    sz++;
                } else {
                    st.push(s[i]);
                    sz++;
                    ans += s[i];
                }
            }

            else if (s[i] == ')') {
                if (sz > 1) {
                    st.pop();
                    sz--;
                    ans += s[i];

                } else {
                    st.pop();
                    sz--;
                }
            }
        }

        return ans;
    }
};