#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	const string HEX = "0123456789abcdef";
    string toHex(int num) {
        if (num == 0)
			return "0";

		int count = 0;
		string res = "";
		while (num && count++ < 8)
		{
			res = HEX[num&0xf] + res;
			num >>= 4;
		}

		return res;
    }
};