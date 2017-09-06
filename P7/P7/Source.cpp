#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
	Reverse digits of an integer.

	Example1: x = 123, return 321
	Example2: x = -123, return -321

	click to show spoilers.

	Note:
	The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

	Subscribe to see which companies asked this question.
*/

class Solution {
public:
    int reverse(int x) {
		vector<int> inNumber;
		bool bFlag = false;
		int result;
		
		if (x >= 0)
			bFlag = true;

		x = abs(x);
		if (x == 0)
			inNumber.push_back(0);

		while (x)
		{
			inNumber.push_back(x%10);
			x /= 10;
		}

		long long cpNumber = 0;
		int N = 0;
		std::reverse(inNumber.begin(), inNumber.end());
		while (inNumber.size() != 0)
		{
		    N = inNumber.at(inNumber.size() - 1) + 10*N;
			cpNumber = inNumber.at(inNumber.size() - 1) + 10*cpNumber;
			inNumber.pop_back();
		}

		if (!bFlag)
		{
			N = N * (-1);
			cpNumber = cpNumber * (-1);
		}

		if (N != cpNumber)
			result = 0;
		else
		{
			result = N;
		}

		return result;
    }
};

int main()
{
	Solution solution;
	cout << solution.reverse(-100) << endl;
	return 0;
}