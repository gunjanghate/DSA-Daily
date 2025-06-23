class Solution {
public:
    string largestGoodInteger(string num) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string ans = "";
        int cnt = 1;

        for (int i = 1; i < num.length(); i++) {
            if (num[i] == num[i - 1]) {
                cnt++;
                if (cnt == 3) {
                    string triple = string(3, num[i]);
                    if (ans == "" || triple > ans) {
                        ans = triple;
                    }
                }
            } else {
                cnt = 1;
            }
        }

        return ans;
    }
};
