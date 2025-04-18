// class Solution {
// private:
//     string helper(string s, int n, int i){
//         if(i > n) return s;

//         string s1 = "";
//         int cnt = 1;
//         //performing rle here
//         for(int j = 1; j <= s.size(); j++) {
//             if(j < s.size() && s[j] == s[j - 1]) {
//                 cnt++;
//             } else {
//                 s1 += to_string(cnt) + s[j - 1];
//                 cnt = 1;
//             }
//         }

//         return helper(s1, n, i + 1);
//     }

// public:
//     string countAndSay(int n) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);

//         if(n == 1) return "1";
//         return helper("1", n, 2);
//     }
// };//7ms
class Solution {
public:
    string countAndSay(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string s = "1";
        for (int i = 2; i <= n; ++i) {
            string temp = "";
            int count = 1;
            for (int j = 1; j <= s.size(); ++j) {
                if (j < s.size() && s[j] == s[j - 1]) {
                    count++;
                } else {
                    temp += to_string(count) + s[j - 1];
                    count = 1;
                }
            }
            s = temp;
        }
        return s;
    }
};
//
