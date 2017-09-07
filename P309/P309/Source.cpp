#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;

		vector<int> profitWithSell(prices.size(), 0);
		vector<int> profitWithNothing(prices.size(), 0);

		profitWithNothing[0] = 0, profitWithSell[0] = 0;
		for (int i = 1; i < prices.size(); ++i)
		{
			profitWithSell[i] = max(profitWithSell[i-1]+prices[i]-prices[i-1],
				profitWithNothing[i-1]);
			profitWithNothing[i] = max(profitWithNothing[i-1], profitWithSell[i-1]);
		}

		return max(profitWithNothing.back(), profitWithSell.back());
    }
};