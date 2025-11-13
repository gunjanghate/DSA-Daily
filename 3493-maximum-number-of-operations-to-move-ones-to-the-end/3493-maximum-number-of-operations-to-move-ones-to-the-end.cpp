class Solution {
public:
    long long maxOperations(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long cnt = 0;
        long long ones = (s[0] == '1');
        int n = s.size();

        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                ones++;
            } else if (s[i - 1] == '1') {
                cnt += ones;
            }
        }

        return cnt;
    }
};
