class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string r1 = "qwertyuiop";
        string r2 = "asdfghjkl";
        string r3 = "zxcvbnm";
        vector<string> ans;

        for (string word : words) {
            int cr1 = 0, cr2 = 0, cr3 = 0;
            for (char c : word) {
                c = tolower(c);
                if (r1.find(c) != string::npos)
                    cr1++;
                else if (r2.find(c) != string::npos)
                    cr2++;
                else if (r3.find(c) != string::npos)
                    cr3++;
            }

            if ((cr1 && !cr2 && !cr3) || (!cr1 && cr2 && !cr3) ||
                (!cr1 && !cr2 && cr3)) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
