class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        if (b == 0) return 1;

        long long half = power(a, b / 2);
        long long res = (half * half) % MOD;

        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }

        return res;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos  = n / 2;

        long long ans = (power(5, evenPos) * power(4, oddPos)) % MOD;
        return ans;
    }
};
