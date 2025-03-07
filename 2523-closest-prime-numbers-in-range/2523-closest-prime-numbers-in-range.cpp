class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;

        for (int num = left; num <= right; num++) {
            if (num % 2 == 0 && num > 2) continue;
            if (isPrime(num)) {
                if (!primes.empty() && num <= primes.back() + 2) {
                    return {primes.back(), num};
                }
                primes.push_back(num);
            }
        }

        if (primes.size() < 2) return {-1, -1};

        vector<int> closest = {-1, -1};
        int minDiff = 1e6;

        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                closest = {primes[i - 1], primes[i]};
            }
        }

        return closest;
    }

private:
    bool isPrime(int n) {
        if (n == 1) return false;
        for (int d = 2; d <= sqrt(n); d++) {
            if (n % d == 0) return false;
        }
        return true;
    }
};
