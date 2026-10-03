class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int open = 0, close = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(')
                open++;
            else
                close++;

            if(open == close) {
                ans = max(ans, 2 * close);
            }
            else if(close > open) {
                open = 0;
                close = 0;
            }
        }

        open = 0;
        close = 0;

        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == '(')
                open++;
            else
                close++;

            if(open == close) {
                ans = max(ans, 2 * close);
            }
            else if(open > close) {
                open = 0;
                close = 0;
            }
        }

        return ans;
    }
};