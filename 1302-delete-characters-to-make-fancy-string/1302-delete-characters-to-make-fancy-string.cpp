class Solution {
public:
    string makeFancyString(string& s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int write = 1, count = 1;

        for (int read = 1; read < s.size(); ++read) {
            if (s[read] == s[read - 1])
                count++;
            else
                count = 1;

            if (count < 3)
                s[write++] = s[read];
        }

        s.resize(write);
        return s;
    }
};
