#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0);
		
		int mark[3] = {1, 1, 1};
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			dp[i] = min(min(dp[mark[0]] * 2, dp[mark[1]] * 3), 
				dp[mark[2]] * 5);
			
			if (dp[mark[0]] * 2 == dp[i])	++mark[0];
			if (dp[mark[1]] * 3 == dp[i])	++mark[1];
			if (dp[mark[2]] * 5 == dp[i])   ++mark[2];
		}

		return dp.back();
    }
};

int main()
{
	Solution s;
	s.nthUglyNumber(20);
}