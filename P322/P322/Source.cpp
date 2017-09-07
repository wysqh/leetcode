#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount+1, 999);
		
		dp[0] = 0;
		for (const auto& coin : coins)
			for (int i = coin; i <= amount; i++)
				dp[i] = min(dp[i-coin]+1, dp[i]);

		return dp.back() == 999 ? -1 : dp.back();
    }
};