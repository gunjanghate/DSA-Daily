class Solution {
public:
    string makeFancyString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int c = 1;
        string ans = "";
        
        for (int i = 0; i < s.length(); i++) {
            if (ans.length() == 0) {
                ans += s[i];
                continue;
            }
            
            if (ans.back() == s[i]) {
                if (c < 2) {
                    ans += s[i];
                    c++;
                }
            } else {
                ans += s[i];
                c = 1;
            }
        }

        return ans;
    }
};
