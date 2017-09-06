#include <vector>
using namespace std;

//75.02%
class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<vector<int>> rtValue(rowIndex);
		
		if (rowIndex == 0)
			return vector<int>();
		
		rtValue[0].push_back(1);
		for (int i = 1; i < rowIndex; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (j == 0 || j == i)
					rtValue[i].push_back(1);

				if (j != 0 && j != i)
					rtValue[i].push_back(rtValue[i-1][j-1]+rtValue[i-1][j]);
			}
		}

		return vector<int>(rtValue[rowIndex-1]);
	}
};
