#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

//11.03%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		deque<int> dp;
		int maxN = 0;
		if (prices.empty())
			return 0;

		dp.push_back(prices[0]);
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] >= dp.back())
				dp.push_back(prices[i]);
			else
			{
				maxN = maxN + dp.back() - dp.front();
				dp.clear();
				
				dp.push_back(prices[i]);
			}
		}

		maxN = maxN + dp.back() - dp.front();

		return maxN;
    }
};