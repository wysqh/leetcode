#include <iostream>
#include <vector>
using namespace std;

//8.07%
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		vector<vector<int>> rtValue(numRows);

		if (numRows == 0)
			return rtValue;
		
		rtValue[0].push_back(1);
		for (int i = 2; i <= numRows; ++i)
		{
			for (int j = 1; j <= numRows; ++j)
			{
				if (j == 1)
					rtValue[i].push_back(1);
				if (j == i)
					rtValue[i].push_back(i);

				if (j != 1 && j != i)
					rtValue[i].push_back(rtValue[i-1][j-2]+rtValue[i-1][j-1]);
			}
		}
	}
};