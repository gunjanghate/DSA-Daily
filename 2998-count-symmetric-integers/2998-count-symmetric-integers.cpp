class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int count = 0;
        for(int i = low ; i<= high; i++){
            string s = to_string(i);
            if (s.length() % 2 != 0) continue;
            int half = s.length() / 2;
            int sum1 = 0, sum2 = 0;

            for (int j = 0; j < half; j++) {
                sum1 += s[j] - '0';
            }
            for (int j = half; j < s.length(); j++) {
                sum2 += s[j] - '0';
            }

            if (sum1 == sum2) count++;

        }
           return count;
    }
};