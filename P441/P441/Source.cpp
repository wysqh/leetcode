#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
		if (n <= 0)
			return 0;

		return floor(-0.5+sqrt((double)2*n+0.25));
    }
};