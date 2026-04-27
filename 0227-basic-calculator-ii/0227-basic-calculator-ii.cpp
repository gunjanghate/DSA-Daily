class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char op = '+';

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];

            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if(op == '+') {
                    st.push(num);
                }
                else if(op == '-') {
                    st.push(-num);
                }
                else if(op == '*') {
                    int top = st.top(); st.pop();
                    st.push(top * num);
                }
                else if(op == '/') {
                    int top = st.top(); st.pop();
                    st.push(top / num);
                }

                op = c;
                num = 0;
            }
        }


        int result = 0;
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};