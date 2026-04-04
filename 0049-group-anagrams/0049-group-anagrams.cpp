class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<string, vector<string>> res;

        for (string& s : strs) {
            vector<int> count(26, 0);

            for (char& c : s) {
                count[c - 'a']++;
            }
            string k;
            for (int i = 0; i < 26; i++) {
                k += '#' + to_string(count[i]);
            }
            res[k].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& [key, grp] : res) {
            result.push_back(grp);
        }
        return result;
    }
};