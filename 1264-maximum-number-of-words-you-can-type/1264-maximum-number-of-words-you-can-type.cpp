class Solution {
public:
    bool isPossible(string broken, string word) {
        for (char c : broken) {
            if (word.find(c) != string::npos)
                return false;
        }
        return true;
    }

    int canBeTypedWords(string text, string brokenLetters) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int cnt = 0;
        string word = "";

        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                if (isPossible(brokenLetters, word)) cnt++;
                word = "";
            } else {
                word += text[i];
            }
        }

        if (!word.empty() && isPossible(brokenLetters, word)) cnt++;

        return cnt;
    }
};
