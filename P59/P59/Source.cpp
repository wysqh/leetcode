#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

//5.77%

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		int size = n * n;
		int index = 1;
		int t = 0, l = 0, r = n - 1, b = n - 1;
		vector<vector<int>> rtValue(n, vector<int>(n, 0));

		while (index <= size)
		{
			int left = l;
			while (left <= r)
				rtValue[l].at(left++) = index++;
			t++;

			int down = t; 
			while (down <= b)
				rtValue[down++].at(r) = index++;
			r--;

			int right = r;
			while (right >= l)
				rtValue[b].at(right--) = index++;
			b--;

			int top = b;
			while (top >= t)
				rtValue[top--].at(l) = index++;
			l++;
		}
		
		return rtValue;
    }
};

int main()
{
	vector<vector<int>> test;
	Solution s;
	test = s.generateMatrix(4);
	for (auto vec : test)
	{
		for (auto e: vec)
			cout << e <<  " ";
		cout << endl;
	}
	return 0;
}