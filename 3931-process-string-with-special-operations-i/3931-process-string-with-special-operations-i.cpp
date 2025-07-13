class Solution {
public:
    string processStr(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        string result;
        for (char i : s) {
            if (islower(i)) {
                result += i;
            } else if (i == '*' && !result.empty()) {
                result.erase(result.size() - 1, 1);
            } else if (i == '#') {
                result.append(result);
            } else if (i == '%') {
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};
