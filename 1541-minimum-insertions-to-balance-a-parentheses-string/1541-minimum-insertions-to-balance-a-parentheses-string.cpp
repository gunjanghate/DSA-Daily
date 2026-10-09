class Solution {
public:
    int minInsertions(string s) {
        // stack<char> st;
        int cnt = 0;
        int res = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                // st.push('(');
                cnt++;
            }
            else {

                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++; 
                }
                else {
                    res++;
                }

                if (cnt>0) {
                    cnt--;
                }
                else {
                    res++; 
                }
            }
        }


        res += 2 * cnt;

        return res;
    }
};