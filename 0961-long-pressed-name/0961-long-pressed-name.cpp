class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0, n = name.length(), m = typed.length();
        if(n > m) return false;
        while (j < m) {
            if (i < n && name[i] == typed[j]) {
                ++i; ++j;
            }
            else if (j && typed[j] == typed[j - 1]) ++j;
            else return false;
        }
        return i == n;
    }
};