class Solution {
public:
    string concatHex36(int n) {
        unordered_map<int, char> mp;

        for (int i = 0; i <= 9; i++) mp[i] = i + '0';
        for (int i = 10; i <= 35; i++) mp[i] = (i - 10 + 'A');

        int n2 = n * n;
        int n3 = n * n * n;

        string res1 = "";
        if (n2 == 0) res1 = "0";
        while (n2 > 0) {
            res1 = mp[n2 % 16] + res1;
            n2 /= 16;
        }
        
        string res2 = "";
        if (n3 == 0) res2 = "0";
        while (n3 > 0) {
            res2 = mp[n3 % 36] + res2;
            n3 /= 36;
        }

        return res1 + res2;
    }
};