class Solution {
public:
    bool noZero(int x) {
        while (x > 0) {
            if (x % 10 == 0) return false;
            x /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int a = 1, b = n - 1;
        while (!noZero(a) || !noZero(b)) {
            a++;
            b = n - a;
        }
        return {a, b};
    }
};
