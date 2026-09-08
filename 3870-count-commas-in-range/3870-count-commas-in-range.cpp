class Solution {
public:
    int countCommas(int n) {
        int count = 0;

        for (int i = n; i >= 0; i--) {
            if(i<=999) break;
                count++;
        }

        return count;
    }
};