#include <iostream>
#include <string>
#include <vector>

using namespace std;


//2.57%

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> rtValue;
		while (matrix.size())
		{
			for (vector<int>::iterator it = matrix[0].begin(); it!=matrix[0].end(); it++)
				rtValue.push_back(*it);
			matrix.erase(matrix.begin());

			for (int i = 0; matrix.size() && i < matrix.size(); i++)
			{
				rtValue.push_back(matrix[i].at(matrix[i].size()-1));
				matrix[i].erase(matrix[i].begin() + matrix[i].size() - 1);
			}
			if (matrix[0].size() == 0)
			{
				for (vector<vector<int>>::iterator it = matrix.begin(); it!=matrix.end();)
					it = matrix.erase(it);
			}

			if (matrix.size())
			{
				for (vector<int>::reverse_iterator it = matrix[matrix.size()-1].rbegin(); it!=matrix[matrix.size()-1].rend(); it++)
					rtValue.push_back(*it);
				matrix.erase(matrix.begin() + matrix.size()-1);
			}

			if(matrix.size())
			{
				for (int i = matrix.size() - 1; i >=0 ; i--)
				{
					rtValue.push_back(matrix[i].at(0));
					matrix[i].erase(matrix[i].begin());
				}
			}
			if (matrix[0].size() == 0)
			{
				for (vector<vector<int>>::iterator it = matrix.begin(); it!=matrix.end();)
					it = matrix.erase(it);
			}
		}

		return rtValue;
    }
};

int main()
{
	Solution s;
	vector<vector<int>> test;
	vector<int> a(1,7);
	vector<int> b(1,9);
	vector<int> c(1,8);
	test.push_back(a);
	test.push_back(b);
	test.push_back(c);
	s.spiralOrder(test);
	return 0;
}