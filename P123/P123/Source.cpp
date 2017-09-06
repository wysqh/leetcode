#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
	return (a  < b);
}

//4.53%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int size = prices.size();
		vector<vector<int>> local(size, vector<int>(3, 0));
		vector<vector<int>> global(size, vector<int>(3, 0));
		if (prices.empty() || prices.size() == 1)
			return 0;

		for (int i = 1; i < prices.size(); ++i)
		{
			int diff = prices[i] - prices[i-1];
			for (int j = 1; j < 3; j++)
			{
				local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff);
				global[i][j] = max(global[i-1][j], local[i][j]);
			}
		}

		return global[size-1][2];
    }
};