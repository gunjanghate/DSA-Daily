class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (const auto& item : knowledge) {
            mp[item[0]] = item[1];
        }

        string ans = "";
        string key = "";
        bool isKey = false;

        for (char c : s) {
            if (c == '(') {
                isKey = true;
            } else if (c == ')') {
                isKey = false;
                auto it = mp.find(key);
                if (it != mp.end()) {
                    ans += it->second;
                } else {
                    ans += '?';
                }
                key.clear();
            } else if (isKey) {
                key += c;
            } else {
                ans += c;
            }
        }

        return ans;
    }
};