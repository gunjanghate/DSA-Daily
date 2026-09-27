class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<string> st;

        string curr;

        for(auto i : s){
            if(i=='('){
                st.push(curr);
                curr.clear();
            }else if(i==')'){
                reverse(curr.begin(), curr.end());
                curr = st.top() + curr;
                st.pop();
            }else{
                curr += i;
            }
        }

        return curr;
    }
};