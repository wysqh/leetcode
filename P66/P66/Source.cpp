#include <string>
#include <vector>
#include <iostream>
using namespace std;

//17.06%

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		if (digits.size() == 0)
			return digits;

		int m = digits.at(digits.size() - 1);
		int carry = (m + 1) /10;
		digits.at(digits.size() - 1) = (m + 1) % 10;
		for (int i = digits.size() - 2; i >= 0; --i)
		{
			if (digits[i] + carry == 10)
			{
				digits[i] = 0;
				carry = 1;
			}
			else
			{
				digits[i] = digits[i] + carry;
				carry = 0;
			}
		}

		vector<int> rtValue;
		if (carry == 0)
			rtValue = digits;
		else
		{
			rtValue.push_back(1);
			for (auto e : digits)
				rtValue.push_back(e);
		}

		return rtValue;
    }
};