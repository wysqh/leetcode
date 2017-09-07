#include <iostream>
#include <bitset>
#include <stdint.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
		uint32_t flag = 1, base = 1, val = 0;
		while (num)
		{
			if ((1&num) == 0)
				val += base;

			base <<= 1;
			num >>= 1;
		}

		return val;
	}
};

int findComplement(int num) {
    unsigned mask = ~0;
    while (num & mask) mask <<= 1;
    return ~mask & ~num;
}

int main()
{
	cout << std::hex << ~0;
}
