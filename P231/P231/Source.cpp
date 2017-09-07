#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
		int x = n;
		if (n <= 0)
			return false;

		while (x % 2 == 0)
			x /= 2;

		return x == 1;
    }
};