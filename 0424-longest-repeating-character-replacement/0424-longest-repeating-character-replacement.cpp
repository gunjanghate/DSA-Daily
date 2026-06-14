class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26, 0);

        int i = 0;
        int ans = 0;
        int maxFreq = 0;

        for (int j = 0; j < s.length(); j++) {

            hash[s[j] - 'A']++;

            maxFreq = max(maxFreq, hash[s[j] - 'A']);

            while ((j - i + 1) - maxFreq > k) {
                hash[s[i] - 'A']--;
                maxFreq = 0;
                for (int x : hash)
                    maxFreq = max(maxFreq, x);

                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};