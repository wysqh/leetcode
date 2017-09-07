#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
		vector<int> dp(n+1, 0);
		dp[1] = 0;
		for (int i = 2; i <= n; i++)
		{
			int multi = 1;
			if (i - 1 > 10)
			{
				dp[i] = dp[i-1] + pow(10, i) - pow(10, i-1);
				continue;
			}
			for (int start = 9, j = 0; j < i - 1; j++, start--)
				multi *= start;
			dp[i] = dp[i-1] + pow(10, i) - pow(10, i-1) - 9 * multi;
		}

		return pow(10, n) - dp[n];
	}
};

int main()
{
	Solution s;
	cout << pow(10, 10);
	//cout << s.countNumbersWithUniqueDigits(4);
}