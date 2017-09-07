#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		unordered_map<int, int> memo;
		for (const auto& s : special)
			memo.insert(pair<int, int>(getKey(vector<int>(begin(s), end(s)-1)), s[s.size() - 1]));
        
        int unbelievable_cost = 0;
        for (int i = 0; i < price.size(); ++i)
					unbelievable_cost += price[i] * needs[i];
		return min(minOffers(price, special, needs, memo), unbelievable_cost);
    }

	int minOffers(vector<int>& prices, vector<vector<int>>& special, vector<int> needs,
		unordered_map<int, int> memo)
	{
		for (const auto& need: needs)
			if (need < 0)
				return 0;

		if (memo.find(getKey(needs)) != memo.end())
			return memo[getKey(needs)];
		int minCost = INT_MAX;
		for (const auto& s : special)
		{
			for (int i = 0; i < s.size() - 1; i++)
				needs[i] -= s[i];
		
			int cost = minOffers(prices, special, needs, memo);
            for (int i = 0; i < s.size() - 1; i++)
                needs[i] += s[i];
			if ( cost != 0)
			{
				cost += memo[getKey(vector<int>(begin(s), end(s)-1))];
			}
			else
			{
				for (int i = 0; i < prices.size(); ++i)
					cost += prices[i] * needs[i];
			}

			minCost = (cost < minCost) ? cost : minCost;
		}

		memo.insert(pair<int, int>(getKey(needs), minCost));
		return minCost;
	}

	int getKey(const vector<int>& a)
	{
		int k = 0;
		for (int i = a.size() - 1,  p = 1; i >= 0; i--, p*=10)
		{
			k += a[i] * p;
		}

		return k;
	}
};