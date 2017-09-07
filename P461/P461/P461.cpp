#include <iostream>
#include <stdint.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
		uint32_t num = x^y, count = 0;
		while(num)
		{
			++count;
			num &= num-1;
		}

		return count;
    }
};