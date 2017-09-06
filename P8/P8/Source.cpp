#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	Implement atoi to convert a string to an integer.

	Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

	Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

	Update (2015-02-10):
	The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/
class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
		double comNumber = 0;
		bool bFlag = false;
		bool bSkip = false;
		string filterStr;
		string filter;
		vector<int> cBits(str.size(), 0);
		for (int i = 0; i < str.size(); i++)
		{
			if (str.at(i) == ' ' && !bSkip)
				continue;
			else
			{
				bSkip = true;
			}

			if (str.at(i) == ' ' && bSkip)
				cBits.at(i) = '1';
		}
		
		for (int i = 0; i < str.size(); i++)
		{
			if (cBits[i] != 0)
				break;
			
			filterStr += str.at(i);
		}

		for ( auto e : filterStr)
			if (e != ' ')
				filter += e;
		filterStr = filter;
		if (filterStr.size() && filterStr.at(0) == '+')
			filterStr.at(0) = '0';
		if (filterStr.size() && filterStr.at(0) == '-')
		{
			bFlag = true;
			filterStr.at(0) = '0';
		}

		
		for (auto c: filterStr)
		{
			if (c > '9' || c < '0')
				break;

			result = c - '0' + 10 * result;
			comNumber = c - '0' + 10 * comNumber;
		}
		
		if (bFlag)
		{
			result *= -1;
			comNumber *= -1;
		}

		if (result != comNumber && !bFlag)
			result = INT_MAX;
		if (result != comNumber && bFlag)
			result = -(INT_MAX+1);
		return result;
    }
};

int main()
{
	Solution solution;
	cout << solution.myAtoi("  234eae2") << endl;
	return 0;
}