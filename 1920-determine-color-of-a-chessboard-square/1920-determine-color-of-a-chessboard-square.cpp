class Solution {
public:
    bool squareIsWhite(string c1) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        map<char, int> mp = {{'a', 1}, {'b', 0}, {'c', 1}, {'d', 0},
                             {'e', 1}, {'f', 0}, {'g', 1}, {'h', 0}};
        char a, b;
        int c, d;
        a = c1[0];
        c = c1[1] - '0';
        string f1 = "", f2 = "";
        if (mp[a] == 1) {
            if (c % 2 != 0) {
                f1 = "black";
            } else {
                f1 = "white";
            }
        } else {
            if (c % 2 == 0) {
                f1 = "black";
            } else {
                f1 = "white";
            }
        }

        if (f1 == "black")
            return false;
        return true;
    }
};