#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/*
	Given a roman numeral, convert it to an integer.

	Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    int romanToInt(string s) {
		int number[13] = {1000, 900, 500, 400, 100,90, 50, 40, 10, 9, 5, 4, 1};  
        string flags[13] = {"M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};  
		int result = 0;

		for (int i = 0; i < s.size(); i++)
		{
			string ch;
			stringstream stream;
			stream << s.at(i);
			ch = stream.str();
			if ((ch == "C" || ch == "X" || ch == "I") && i+1 < s.size() )
			{
				if (ch + s.at(i+1) == flags[1])
				{
					result += 900;
					i++;
					continue;
				}
				else if (ch + s.at(i+1) == flags[3])
				{
					result += 400;
					i++;
					continue;
				}
				else if (ch + s.at(i+1) == flags[5])
				{
					result += 90;
					i++;
					continue;
				}
				else if (ch + s.at(i+1) == flags[7])
				{
					result += 40;
					i++;
					continue;
				}
				else if (ch + s.at(i+1) == flags[9])
				{
					result += 9;
					i++;
					continue;
				}
				else if (ch + s.at(i+1) == flags[11])
				{
					result += 4;
					i++;
					continue;
				}
				
			}

			int index = findByCh(ch, flags);
			result += number[index];
		}

		return result;
    }

	int findByCh(string ch, string flag[])
	{
		int i = 0;
		for (i = 0; i < 13; i++)
		{
			if (ch == flag[i])
			{
				break;
			}
		}
		return i;
	}
};

int main()
{
	Solution solution;
	cout << solution.romanToInt("DCXXI") << endl;
	return 0;
}