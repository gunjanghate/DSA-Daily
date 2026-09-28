class Solution {
public:
    int maxDepth(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int cnt = 0;
        int ans = 0;
        for (auto ch : s) {
            if (ch == '(') {
                cnt++;
                ans = max(ans, cnt);
            } else if (ch == ')') {
                cnt--;
            } else {
                continue;
            }
        }
        
        return ans;
    }
};