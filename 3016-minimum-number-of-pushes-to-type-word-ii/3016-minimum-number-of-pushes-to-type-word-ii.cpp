class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> letters(26,0);
        for(int i = 0; i<n; i++){
           letters[word[i]- 'a']++;
        }

        sort(letters.begin(), letters.end(), greater<int>());

        int btn = 0;
        int turn = 1;
        int ans = 0;
        for(int i = 0; i<26; i++){
            ans += letters[i] * turn;
            btn++;
            if(btn==8){
                btn = 0;
                turn++;
            }
        }

        return ans;
    }
};