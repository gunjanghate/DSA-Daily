class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        vector<string> ans;
        int i = 0;

        while (i < n) {
            string part;

            if (i + k <= n) {
                part = s.substr(i, k);
            } else {
                part = s.substr(i);
                part += string(k - part.length(), fill); 
            }

            ans.push_back(part);
            i += k;
        }

        return ans;
    }
};
