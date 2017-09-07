#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
		vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
		vector<vector<int>> products(nums.size(), vector<int>(nums.size(), 0));

		for (int len = 1; len <= nums.size(); len++)
			for (int i = 0; i + len <= nums.size(); i++)
			{
				int j = i + len - 1;
				if ( i == j)  dp[i][j] = products[i][j] = nums[i];
				else
				{
					products[i][j] = products[i+1][j] * nums[i];
					dp[i][j] = max(max(dp[i+1][j], dp[i][j-1]), products[i][j]);
				}
			}
			
			return dp[0].back();
    }
};

int main()
{
	int a[] = {1,2,3,4,5,6};
	vector<int> test(begin(a), end(a));
	Solution s;
	s.maxProduct(test);
}