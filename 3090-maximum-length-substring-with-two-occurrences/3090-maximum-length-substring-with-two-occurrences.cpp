class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int, int> mp;
        int b = 0;
        int ans = 0;
        for(int i = 0; i<s.length(); i++){
            mp[s[i]]++;
            while(mp[s[i]]>2){
                mp[s[b]]--;
                b++;
            }

            ans = max(ans, i - b + 1);

        }

        return ans;
    }
};