#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        stack<int> st;
        int i = 0;
        int n = s.length();

        while (i < n) {

            if (s[i] == ' ') {
                i++;
                continue;
            }

            if (isdigit(s[i])) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                // check for * or /
                if (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                    char op = st.top(); st.pop();
                    int n1 = st.top(); st.pop();

                    if (op == '*') st.push(n1 * num);
                    else st.push(n1 / num);
                } else {
                    st.push(num);
                }

                continue;
            }

            st.push(s[i]);
            i++;
        }

        // second pass for + and -
        stack<int> st2;

        while (!st.empty()) {
            st2.push(st.top());
            st.pop();
        }

        ans = st2.top();
        st2.pop();

        while (!st2.empty()) {
            char op = st2.top(); st2.pop();
            int num = st2.top(); st2.pop();

            if (op == '+') ans += num;
            else if (op == '-') ans -= num;
        }

        return ans;
    }
};