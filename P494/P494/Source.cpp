#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

//Subset Sum;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
		int count = 0;
		//helper(nums, S, 0, count);
		return dpBasedSolution(nums, S);
		//return count;
    }

	int dpBasedSolution(vector<int>& nums, int S)
	{
		int target = (std::accumulate(begin(nums), end(nums), 0) + S) / 2;
		if (S > 1000 || std::accumulate(begin(nums), end(nums), 0) + S & 1 || 
            S > std::accumulate(begin(nums), end(nums), 0))
            return 0;
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		
		for (const auto&e: nums)
		{
			for (int i = target; i >= e; i--)
			{
				dp[i]+= dp[i-e];
				cout << dp[i] << " ";
			}
			cout << endl;
		}

		return dp[target];
	}

	void helper(vector<int>& nums, int S, int dex, int& count)
	{
		if (dex == nums.size())
		{
			if (S == 0)	count ++;
			return;
		}

		helper(nums, S-nums[dex], dex+1, count);
		helper(nums, S+nums[dex], dex+1, count);

		return;
	}
};

int main()
{
	Solution s;
	int nums[] = {1,1,1,1,1};
	int S = 3;
	vector<int> test(begin(nums), end(nums));
	cout << s.findTargetSumWays(test, S) << endl;
}