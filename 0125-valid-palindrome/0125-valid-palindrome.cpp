class Solution {
public:
    string cleanString(const string& s) {
        string result;
        for (char c : s) {
            if (isalnum(c)) {
                result += tolower(c);
            }
        }
        return result;
    }
    bool helper(string& s, int i) {
        if (i >= s.length() / 2)
            return true;
        if (s[i] != s[s.length() - i - 1])
            return false;
        return helper(s, i + 1);
    }
    bool isPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        s = cleanString(s);

        return helper(s, 0);
    }
};