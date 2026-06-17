class Solution {
  public:
    string minWindow(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();

        int start = -1;
        int minLen = INT_MAX;

        int i = 0;

        while (i < n) {

            int j = 0;

            // Forward scan: find a complete match of s2
            while (i < n) {
                if (s1[i] == s2[j]) {
                    j++;

                    if (j == m)
                        break;
                }
                i++;
            }

            if (i == n)
                break;

            int end = i;

            // Backward scan: minimize window
            j = m - 1;

            while (j >= 0) {
                if (s1[i] == s2[j])
                    j--;

                i--;
            }

            i++; // actual start of minimized window

            int len = end - i + 1;

            if (len < minLen) {
                minLen = len;
                start = i;
            }

            // Continue search from next position
            i = i + 1;
        }

        return start == -1 ? "" : s1.substr(start, minLen);
    }
};