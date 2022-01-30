class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n,false);

        for (int i = 2; i * i < primes.size(); i++) {
            if (!primes[i]) {
                for (int j = i; i * j < primes.size(); j++) {
                    primes[i * j] = true;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < primes.size(); i++)
            if (!primes[i]) count++;
        return count;
    }
};
