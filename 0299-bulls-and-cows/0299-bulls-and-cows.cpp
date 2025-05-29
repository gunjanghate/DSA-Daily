class Solution {
public:
    string getHint(string secret, string guess) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int bulls = 0, cows = 0;
        int l = secret.length();
        unordered_map<char, int> secmp;
        unordered_map<char, int> guemp;

        for (int i = 0; i < l; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                secmp[secret[i]]++;
                guemp[guess[i]]++;
            }
        }

        for (auto& [ch, cnt] : guemp) {
            if (secmp.find(ch) != secmp.end()) {
                cows += min(cnt, secmp[ch]);
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
