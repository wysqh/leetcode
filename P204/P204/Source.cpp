#include <iostream>
#include <vector>
using namespace std;

//the Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
		prime[0] = false, prime[1] = false;
		
		for (int i = 0; i < sqrt(n); ++i)
			if (prime[i])
				for (int j = i*i; j < n; j+=i)
					prime[j] = false;

		return count(begin(prime), end(prime), true);
    }
};
