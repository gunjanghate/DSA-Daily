class Solution {
public:
    string solve(string b) {
        int add = 0;
        for (auto c : b) {
            add += c - '0';
        }
        return to_string(add);
    }

    string digitSum(string s, int k) {
        while (s.length() > k) {
            string next_s = "";
            for (int j = 0; j < s.length(); j += k) {
                next_s += solve(s.substr(j, k));
            }
            s = next_s;
        }

        return s;
    }
};