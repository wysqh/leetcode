#include <iostream>
#include <string>
#include <vector>

using namespace std;
//12.04%

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> rtValue;
		vector<int> container;
		solve(rtValue, container, k, n, 0, 1);
    }

	void solve(vector<vector<int>> &rtValue, vector<int> container, int k, int n, int index, int cur)
	{
		if (index == k)
		{
			rtValue.push_back(container);
			return;
		}

		for (int i = cur; i < n; i++)
		{
			container.push_back(i);
			solve(rtValue, container, k, n, index + 1, i + 1); 
			container.pop_back();
		}
	}
};