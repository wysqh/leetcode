#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		
		vector<int> dp(nums.size(), 1);

		for (int i = 1; i < nums.size(); ++i)
			for (int j = i - 1; j >= 0; --j)
				dp[i] = max(dp[i], nums[i] > nums[j] ? dp[j] + 1 : 1);

		return *max_element(begin(dp), end(dp));
    }
};