class Solution {
public:
    bool isIsomorphic(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<char, int> mp;
        // unordered_map<char,int> mp1;

        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];
            if (mp.count(a)) {

                if (mp[a] != b)
                    return false;
            } else {
                for (auto k : mp)
                    if (k.second == b)
                        return false;
                mp[a] = b;
            }
        }

        return true;
    }
};