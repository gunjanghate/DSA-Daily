class Solution {
public:
    vector<int> partitionLabels(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        map<char, int> mp;
        for (auto i : s) {
            mp[i]++;
        }
        string ans = "";
        int n = s.length();
        vector<int> lengths;
        vector<char> store;
        for (int i = 0; i < n; i++) {
            if (store.empty() && mp[s[i]] > 0) {
                store.push_back(s[i]);
                ans += s[i];
                mp[s[i]]--;
            } else {
                if (mp[s[i]] > 0) {
                    int cnt = count(store.begin(), store.end(), s[i]);
                    if (cnt) {
                        ans += s[i];
                        mp[s[i]]--;
                    } else {
                        store.push_back(s[i]);
                        ans += s[i];
                        mp[s[i]]--;
                    }
                }

            }
                if (mp[s[i]] < 1) {
                        store.erase(find(store.begin(), store.end(), s[i]));
                        if(store.empty()){
                        lengths.push_back(ans.length());
                        ans = "";
                        }
                    }

        }

        return lengths;
    }
};