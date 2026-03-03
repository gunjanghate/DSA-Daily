class Solution {
public:
    string invertStr(string s) {
        for (char& c : s)
            c = (c == '0') ? '1' : '0';
        return s;
    }
    char findKthBit(int n, int k) {
        vector<string> s(n);
        s[0] = "0";

        for (int i = 1; i < n; i++) {
            string firstPart = s[i - 1];
            string secondPart = invertStr(s[i - 1]);
            reverse(secondPart.begin(), secondPart.end());
            string newstr = firstPart + '1' + secondPart;
            s[i] = newstr;
        }

        return s[n-1][k-1];
    }
};