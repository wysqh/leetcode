#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    int minSteps(int n) {
//        int count = 0;
//		int follow = 1;
//		int cur = 0;
//		while (follow < n)
//		{
//			if (cur == 0)
//			{
//				cur = follow;
//				count ++;
//			}
//
//			if (follow != 1 && n % follow == 0)
//			{
//				++count;
//				cur = follow;
//			}
//			++ count;
//			follow += cur;
//		}
//
//		return count;
//    }
//};
//
//int main()
//{
//	Solution solution;
//	int n; 
//	cin >> n;
//	cout << solution.minSteps(n) << endl;
//	return 0;
//}

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
  //      int refC = 0;
		//sort(begin(nums), end(nums));
		//recursiveFind(nums, target, refC);
		//return refC;

		  //int dp[4 + 1] = {1} ;
    //    for (int i = 1; i <= target; ++i)
    //        for (int j = 1; j <= nums.size(); ++ j)
    //            if (nums[j - 1] <= i)
    //                dp[i] += dp[i - nums[j - 1]];
    //    return dp[target];
		if (nums.size() == 0)
			return 0;
		vector<int>::iterator it = min_element(begin(nums), end(nums));
		vector<int> dp(target+1);
		dp[*it] = 1;
		dp[0] = 1;
		for (int i = *it+1; i <= target; i++)
			for (int j = 0; j < nums.size(); j++)
			{
				if (nums[j] > i)
					continue;
				dp[i] += dp[i - nums[j]];
			}

			return dp[target];
    }

	int recursiveFind(vector<int>& nums, int target, int& __refCount)
	{
		if (target < 0)
			return -1;

		if (target == 0)
		{
			__refCount++;
			return 0;
		}
		
		for (const auto& e: nums)
		{
			if (recursiveFind(nums, target - e, __refCount) <= 0)
				break;
		}
		return 1;
	}
};

int main()
{
	int nums[] = {2,3, 1};
	vector<int> vec(begin(nums), end(nums));
	Solution s;
	cout << s.combinationSum4(vec, 35) << endl;
}

//dp[i]代表target为i时候，共有几种解法 
//dp[0] = 0;
//dp[min] = 1;
//
//dp[K] += dp[K-num[i]]