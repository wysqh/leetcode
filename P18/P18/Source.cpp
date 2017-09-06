#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

/*
	Given an array S of n integers, are there elements a, b, c, 
	and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

	Note: The solution set must not contain duplicate quadruplets.

	For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

	A solution set is:
	[
	  [-1,  0, 0, 1],
	  [-2, -1, 1, 2],
	  [-2,  0, 0, 2]
	]
*/

//41.53%

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rtValue;
		set<vector<int>> rtSet;
		sort(begin(nums), end(nums));
		
		if (nums.size() <= 3)
			return rtValue;

		for (int i = 0; i < nums.size() - 3; i++)
		{
			int triRes = target - nums.at(i);
			if ((i+5) < nums.size() && nums.at(i+1) ==nums.at(i) && nums.at(i+2) == nums.at(i+1) && nums.at(i+3) == nums.at(i+2) && nums.at(i+4) == nums.at(i+3) && nums.at(i+4) == nums.at(i+5))
					continue;
			for (int j = i + 1; j < nums.size() - 2; j++)
			{
				int biRes = triRes - nums.at(j);
				if ((j+4) < nums.size() && nums.at(j+1) == nums.at(j) && nums.at(j) == nums.at(j+2) && nums.at(j) == nums.at(j+3)&& nums.at(j) == nums.at(j+4))
					continue;

				int head = j + 1, tail = nums.size() - 1;
				while (head < tail)
				{
					if (nums.at(head) + nums.at(tail) == biRes)
					{
						int tmp[] = {nums.at(i), nums.at(j), nums.at(head), nums.at(tail)};
						rtSet.insert(vector<int>(begin(tmp), end(tmp)));
						while (head < tail && nums.at(head) == nums.at(head + 1))  ++head;
						while (head < tail && nums.at(tail) == nums.at(tail - 1))  --tail;

						++head, --tail;
					}
					else if (nums.at(head) + nums.at(tail) < biRes)
						++head;
					else
						--tail;
				}
			}
		}

		return vector<vector<int>>(begin(rtSet), end(rtSet));
    }
};

int main()
{
	int a[] = {1,4,-3,0,0,0,5,0,0};
	vector<int> test(begin(a), end(a));
	Solution solution;
	
	vector<vector<int>> result;
	result = solution.fourSum(test, 0);
	for (auto vec : result)
	{
		for (auto e : vec)
			cout << e << " ";
		cout << endl;
	}
	return 0;
}