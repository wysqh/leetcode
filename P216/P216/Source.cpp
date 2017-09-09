#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> vals;
	vector<int> container;
	vector<bool> used;
    vector<vector<int>> combinationSum3(int k, int n) {
		used.assign(10, false);
		help(0, k, n, 0, 1);

		return vals;
    }

	void help(int index, int& k, int& n, int cur, int start)
	{
		if (index == k)
		{
			if (cur == n)
			{
				vals.push_back(container);
				return;
			}
			return;
		}
		

		for (int i = start; i < 10; i++)
			if (!used[i])
			{
				if (cur + i> n)
					break;

				used[i] = true;
				container.push_back(i);
				help(index+1, k, n, cur + i, i+1);
				container.pop_back();
				used[i] = false;
			}
	}
};