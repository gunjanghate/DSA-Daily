class Solution {
public:
    bool doesAliceWin(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        for (char c : s) {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                return true;
        }
        return false;
    }
};