#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
		bitset<32> bits(num);
		if (bits.count() != 1 || num <= 0)
			return false;

		for (int i = 0; i < 16; ++i, num >>= 2)
			if (num == 1)
				return true;

		return false;
    }
};

bool isPowerOfFour(int num)
{
	return (num > 0) && ((num&(num-1)) == 0) && ((num&0x55555555) == num);
}

int main()
{
	Solution s;
	cout << s.isPowerOfFour(65536);
}