class Solution {
public:
    string removeOuterParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<string> primitives;
        int open = 0, startIndex = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                open++;
            else if (s[i] == ')')
                open--;

            if (open == 0) {
                string primitive = s.substr(startIndex + 1, i - startIndex - 1);
                primitives.push_back(primitive);
                startIndex = i + 1;
            }
        }
        string ans = "";
        for (auto i : primitives)
            ans += i;

        return ans;
    }
};