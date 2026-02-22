class Solution {
public:
    vector<string> key = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    void solve(string digits, vector<string> &ans, string current) {
        if (digits.length() == 0) {
            ans.push_back(current);
            return;
        }

        string letters = key[digits[0] - '0'];

        for (int i = 0; i < letters.length(); i++) {
            solve(digits.substr(1), ans, current + letters[i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.length() == 0)
            return ans;

        solve(digits, ans, "");
        return ans;
    }
};