#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*

*/

class Solution {
public:
    int numSquares(int n) {
		int pack[1000];
		int dp[1000000];

		for (int i = 0; i < INT_MAX; ++i)
			dp[i] = INT_MAX;
		
		for (int i = 0; i < 1000; i++)
			pack[i] = (i+1)*(i+1);
		
		dp[0] = 0, dp[1] = 1;
		for (int i = 2; i <= n; i++)
			for (int j = 0; j < 1000; j++)
				if (i - pack[j] >= 0)
					dp[i] = min(dp[i-pack[j]] + 1, dp[i]);

		return dp[n];
	}
};
//class Solution {
//public:
//    int numSquares(int n) {
//		int root = sqrt(n);
//		vector<int> pack(root, 0);
//		for (int i = 0; i < root; i++)
//			pack[i] = (i+1)*(i+1);
//
//		vector<int> dp(n+1,INT_MAX);
//		dp[0] = 0, dp[1] = 1;
//		for (int i = 2; i <= n; i++)
//			for (const auto& p : pack)
//				if (i - p >= 0)
//					dp[i] = min(dp[i-p] + 1, dp[i]);
//
//		return dp.back();
//	}
//};
int main()
{
	Solution s;
	s.numSquares(30);
}