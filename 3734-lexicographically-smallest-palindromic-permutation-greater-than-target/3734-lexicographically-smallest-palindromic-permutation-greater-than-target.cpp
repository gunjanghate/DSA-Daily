class Solution {
public:
    bool solve(string curr, string target, vector<int>& freq, int i,
               bool isGreater, string& res, char& midChar, int& halfLen) {
        if (i == halfLen) {
            string temp = curr;
            reverse(temp.begin(), temp.end());
            string right = temp;

            if (midChar != '$')
                curr += midChar;

            curr += right;

            if (curr > target) {
                res = curr;
                return true;
            } else
                return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] == 0)
                continue;
            if (!isGreater && ch < target[i])
                continue;

            freq[ch - 'a']--;
            curr.push_back(ch);

            bool g = isGreater || ch > target[i];

            if (solve(curr, target, freq, i + 1, g, res, midChar, halfLen))
                return true;

            curr.pop_back();
            freq[ch - 'a']++;
        }

        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26, 0);
        int n = s.length();
        char midChar = '$';
        int leftHalf = 0;

        for (auto i : s)
            freq[i - 'a']++;
        int oddCnt = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                oddCnt++;
                midChar = i + 'a';
            }
        }

        if (oddCnt > 1)
            return "";

        for (int i = 0; i < 26; i++) {
            freq[i] /= 2;
        }

        leftHalf = n / 2;

        string curr = "";
        string res;

        solve(curr, target, freq, 0, false, res, midChar, leftHalf);

        return res;
    }
};