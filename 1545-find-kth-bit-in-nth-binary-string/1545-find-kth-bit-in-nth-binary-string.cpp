class Solution {
public:
    string invertStr(string s) {
        for (char& c : s)
            c = (c == '0') ? '1' : '0';
        return s;
    }
    char findKthBit(int n, int k) {
        // vector<string> s(n);
        string last = "0";

        for (int i = 1; i < n; i++) {
            string firstPart = last;
            string secondPart = invertStr(last);
            reverse(secondPart.begin(), secondPart.end());
            string s = firstPart + '1' + secondPart;
            last = s;
        }

        return last[k-1];
    }
};