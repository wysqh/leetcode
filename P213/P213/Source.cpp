#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
		vector<int> rb1(begin(nums), end(nums) - 1);
		vector<int> rb2(begin(nums)+1, end(nums));

		return max(robber(rb1), robber(rb2));
	}

	int robber(vector<int>& nums)
	{
		vector<int> dp(nums.size(), 0);
		if (nums.size() < 2)
			return nums.size() ? nums[0] : 0;

		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++)
			dp[i] = max(dp[i-2]+nums[i], dp[i-1]);

		return dp.back();
	}
};



int main()
{
	Solution s;
	int a[] = {12,5,6,7,14};
	vector<int> ss(begin(a), end(a));

	cout << s.rob(ss) << endl;
}