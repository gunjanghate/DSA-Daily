class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int ans = 0;
        int index = 0;

        while (n > 0) {
            if (n & 1) {
                if (last != -1) {
                    ans = max(ans, index - last);
                }
                last = index;
            }
            index++;
            n >>= 1;
        }

        return ans;
    }
};