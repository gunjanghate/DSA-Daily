class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        map<char, int> mp = {{'a', 1}, {'b', 0}, {'c', 1}, {'d', 0},
                             {'e', 1}, {'f', 0}, {'g', 1}, {'h', 0}};
        char a, b;
        int c, d;
        a = c1[0];
        b = c2[0];
        c = c1[1] - '0';
        d = c2[1] - '0';
        string f1 = "", f2 = "";
        if (mp[a]==1) {
            if (c % 2 != 0) {
                f1 = "black";
            } else {
                f1 = "white";
            }
        } else {
            if (c% 2 == 0) {
                f1 = "black";
            } else {
                f1 = "white";
            }
        }

        if (mp[b]==1) {
            if (d % 2 != 0) {
                f2 = "black";
            } else {
                f2 = "white";
            }
        } else {
            if (d % 2 == 0) {
                f2 = "black";
            } else {
                f2 = "white";
            }
        }
        if(f1==f2) return true;
        return false;
    }
    };