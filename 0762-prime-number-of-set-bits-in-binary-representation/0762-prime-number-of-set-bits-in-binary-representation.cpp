class Solution {
public:
    bool isPrime(long long n) {
        if (n <= 1)
            return false;

        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int a = __builtin_popcount(i);
            if (isPrime(a))
                ans++;
        }

        return ans;
    }
};