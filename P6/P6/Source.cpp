#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	Total Accepted: 136618
	Total Submissions: 523204
	Difficulty: Medium
	Contributors: Admin
	The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

	P   A   H   N
	A P L S I I G
	Y   I   R
	And then read line by line: "PAHNAPLSIIGYIR"
	Write the code that will take a string and make this conversion given a number of rows:

	string convert(string text, int nRows);
	convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int numRows) {
		vector<vector<char>> chVec(numRows, vector<char>(0));
		int size = s.size();
		int index = 0;
		if (numRows >= 3)
		{
			while (index < size)
			{
				for (int i = 0; i < numRows; i++)
				{
					if (index + i >= size)
						break;

					chVec[i].push_back(s.at(index+i));
				}
				for (int i = 0; i < numRows - 2; i++)
				{
					if (index + numRows + i >= size)
						break;

					chVec[numRows-i-2].push_back(s.at(index+numRows+i));
				}

				index += 2 * numRows - 2;
			}
		}
		else if (numRows == 2)
		{
			int size = s.size();
			for (int i = 0, j = 1; i < size && j < size; i+=2, j+=2)
			{
				chVec[0].push_back(s.at(i));
				chVec[1].push_back(s.at(j));
			}
			if (size % 2 != 0)
				chVec[0].push_back(s.at(s.size() - 1));
		}
		else
		{
			for (auto e: s)
				chVec[0].push_back(e);
		}
		
		string result = "";
		for (int i = 0; i < numRows; i++)
		{
			for (auto e : chVec[i])
				result += e;
		}

		return result;
    }
};

int main()
{
	Solution solution;
	cout << solution.convert("ABCDE", 2) << endl;
	return 0;
}