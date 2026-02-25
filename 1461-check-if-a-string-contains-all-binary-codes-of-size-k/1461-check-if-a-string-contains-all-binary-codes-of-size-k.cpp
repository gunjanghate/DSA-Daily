class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.length()) return false;

        unordered_set<string> codes;

        for (int i = 0; i + k <= s.length(); i++) {
            codes.insert(s.substr(i, k));
        }

        return codes.size() == pow(2, k);
    }
};