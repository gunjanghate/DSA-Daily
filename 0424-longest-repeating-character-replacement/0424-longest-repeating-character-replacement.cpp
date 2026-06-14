class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;

        int i = 0;
        int ans = 0;
        int maxFreq = 0;

        for(int j = 0; j < s.length(); j++) {

            mp[s[j]]++;

            maxFreq = max(maxFreq, mp[s[j]]);

            while((j - i + 1) - maxFreq > k) {
                mp[s[i]]--;
                 maxFreq = max(maxFreq, mp[s[i]]);
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);


                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};