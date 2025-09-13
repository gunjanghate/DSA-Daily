class Solution {
public:
    bool isVowel(char c) {
        return (c=='a'|| c=='e'|| c=='i' || c=='o' || c=='u');
    }

    int maxFreqSum(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int mx1 = 0, mx2 = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (isVowel('a' + i)) {
                    mx1 = max(mx1, freq[i]);
                } else {
                    mx2 = max(mx2, freq[i]);
                }
            }
        }

        return mx1 + mx2;
    }
};
