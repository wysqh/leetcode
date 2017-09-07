#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
		vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
		
		for (int len = 1; len <= nums.size(); len++)
			for (int i = 0; i + len <= nums.size(); i++)
			{
				int j = i + len - 1;
				if ( i - j == 0)
					dp[i][j] = nums[i];
				else if (j - i == 1)
					dp[i][j] = max(nums[i], nums[j]);
				else
				{
					dp[i][j] = max(accumulate(begin(nums)+i+1, begin(nums)+j+1, 0)
						- dp[i+1][j] + nums[i], 
						accumulate(begin(nums)+i, begin(nums)+j, 0)
						- dp[i][j-1] + nums[j]);
				}
			}

		return 2 * dp[0].back() >= accumulate(begin(nums), end(nums), 0);
    }
};