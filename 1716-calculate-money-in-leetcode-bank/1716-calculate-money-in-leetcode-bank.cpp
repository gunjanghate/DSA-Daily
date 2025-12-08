class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int limit = 7;
        int cur = 1;
        int lastMon = cur;
        for (int i = 1; i <= n; i++) {
            sum += (cur );
            cur++;
            if ((i + 1) > limit) {
                limit += 7;
                cur = lastMon + 1;
                lastMon = cur;
            }
            
        }

        return sum;
    }
};