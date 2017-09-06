#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//1.41%

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
		set<int> columns;

		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
                if (matrix[i][j] == 0)
                {
                    rows.insert(i);
                    columns.insert(j);
                }
			}
		}
		
		for (auto r : rows)
		    for (int i = 0; i < matrix[0].size(); i++)
		        matrix[r][i] = 0;
		        
		for (auto c : columns)
		    for (int i = 0; i < matrix.size(); i++)
		        matrix[i][c] = 0;
    }

	template<class T>
	bool contain(set<T> vec, T data)
	{
		for (auto e : vec)
			if ( e == data)
				return true;

		return false;
	}
};

int main()
{

	return 0;
}