#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
	Given an integer, convert it to a roman numeral.

	Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    string intToRoman(int num) {
	    int number[13] = {1000, 900, 500, 400, 100,90, 50, 40, 10, 9, 5, 4, 1};  
        string flags[13] = {"M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};  
		string result = "";
		
		int i = 0;
		while (num != 0)
		{
			if (num < number[i])
			{
				i++;
				continue;
			}

			num -= number[i];
			result += flags[i];
		}

		return result;
    }
};

int main()
{
	Solution solution;
	for (int i = 1; i < 300; i++)
		cout << solution.intToRoman(i) << endl;
	return 0;
}