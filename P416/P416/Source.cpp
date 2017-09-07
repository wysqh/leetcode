#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
		int sumN = std::accumulate(begin(nums), end(nums), 0);
		if (sumN % 2 != 0)
			return false;

		int half = sumN / 2;
		vector<bool> dp(half+1);
		dp[0] = true;
		for (const auto&num : nums)
			for (int i = half; i >= num; --i)
				dp[i] = dp[i] || dp[i-num];

		return dp[half];
    }
};