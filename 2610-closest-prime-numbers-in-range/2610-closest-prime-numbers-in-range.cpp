class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        //// Sieve of Eratosthenes ////
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        //////////////////////////////
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        if (primes.size() < 2)
            return {-1, -1};

        int minDiff = INT_MAX;
        int num1 = -1, num2 = -1;

        for (int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < minDiff) {
                minDiff = diff;
                num1 = primes[i];
                num2 = primes[i + 1];
            }
        }

        return {num1, num2};
    }
};
