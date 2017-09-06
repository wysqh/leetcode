#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//6.26%

class Solution {
public:
    string addBinary(string a, string b) {
		int i = a.size() - 1, j = b.size() - 1;
		string rtValue = "";
		char carry = '0';
		while (i >= 0 && j >= 0)
		{
			rtValue += a.at(i) ^ b.at(j) ^ carry;
			if ((a.at(i) == '1' && b.at(j) == '1') || (a.at(i) == '1' && carry == '1') || (b.at(j) == '1' && carry == '1'))
				carry = '1';
			else
				carry = '0';
			--i, --j;
		}

		while (i>=0)
		{
			rtValue += a.at(i) ^ carry ^ '0';
			if (a.at(i) == '1' && carry == '1')
				carry = '1';
			else
				carry = '0';
			--i;
		}

		while (j>=0)
		{
			rtValue += b.at(j) ^carry ^ '0';
			if (b.at(j) == '1' && carry == '1')
				carry = '1';
			else
				carry = '0';
			--j;
		}

		if (carry == '1')
			rtValue.push_back('1');

		reverse(begin(rtValue), end(rtValue));

		return rtValue;
    }
};

int main()
{
	Solution s;
	s.addBinary("11011","1011");
	return 0;
}