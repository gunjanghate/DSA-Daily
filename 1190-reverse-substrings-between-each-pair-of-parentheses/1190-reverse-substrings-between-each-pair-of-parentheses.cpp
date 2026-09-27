class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<char> st;

        for(int i = 0; i < n; i++) {

            if(s[i] == ')') {

                string curr = "";

                while(st.top() != '(') {
                    curr += st.top();
                    st.pop();
                }


                st.pop();

                cout << "curr is: " << curr << endl;

                for(char ch : curr) {
                    st.push(ch);
                }

            } else {
                st.push(s[i]);
            }
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};