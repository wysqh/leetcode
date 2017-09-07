#include <iostream>
#include <stdint.h>
#include <iomanip>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		uint32_t flag = 0x80000000, val = 0, base = 1;
		while (flag)
		{
			if (n&flag)
				val += base;

			flag >>= 1;
			base <<= 1;
		}
	
		return val;
    }
};

int main()
{
	Solution s;
	cout << s.reverseBits(1);
}