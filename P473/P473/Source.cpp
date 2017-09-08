#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
		if (nums.empty())
			return false;

		int sum = std::accumulate(begin(nums), end(nums), 0);
		if (sum % 4 != 0)
			return false;
		
		int size = sum / 4;
		std::sort(begin(nums), end(nums), [](const int&a, const int&b)->bool{
			return a > b;
		});

		vector<int> sizeLength(4, 0);
		return dfs(nums, sizeLength, 0, size);
	}

	bool dfs(vector<int>& nums, vector<int>& sizeLength, int index, int& sum)
	{
		if (index == nums.size())
			return (sizeLength[0] == sizeLength[1]) && (sizeLength[2] == sizeLength[3]) &&
			(sizeLength[1] == sizeLength[2]);

		for (int i = 0; i < 4; i++)
		{
			if (sizeLength[i] + nums[index] > sum)
				continue;

			sizeLength[i] += nums[index];
			if (dfs(nums, sizeLength, index+1, sum))
				return true;
			sizeLength[i] -= nums[index];
		}

		return false;
	}
};
