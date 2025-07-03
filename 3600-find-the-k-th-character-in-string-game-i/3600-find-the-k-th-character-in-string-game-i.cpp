class Solution {
public:
    char kthCharacter(int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string s = "a";
        if (k == 2)
            return 'b';
        
        while (s.length() < k) {
            string b = "";
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == 'z') {
                    b += 'a';
                } else {
                    b += char(s[i] + 1);
                }
            }
            s += b;
        }

        return s[k - 1]; 
    }
};
