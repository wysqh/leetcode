#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
		string res(num1.size() + num2.size(), '0');

		for (int i = num1.size() - 1; i >= 0; --i)
		{
			int carry = 0;
			for (int j = num2.size() - 1; j >= 0; --j)
			{
				int tmp = (res[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
				res[i+j+1] = tmp % 10 + '0';
				carry = tmp / 10;
			}
			res[i] += carry;
		}

		size_t startpos = res.find_first_not_of("0");
		if (string::npos != startpos)
			return res.substr(startpos);

		return "0";
    }
};