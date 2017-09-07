#include <iostream>
#include <string>
#include <vector>
using namespace std;

//24.56%
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> rtValue;
		vector<int> container;

		findAll(rtValue, container, nums, 0, nums.size());
		rtValue.push_back(vector<int>());

		return rtValue;
    }

	void findAll(vector<vector<int>> &rtValue, vector<int> container, vector<int> nums, int index, int n)
	{
		if (index == n)
		{
			rtValue.push_back(container);
			return;
		}

		for (int i = index; i < n; i++)
		{
			container.push_back(nums.at(i));
			findAll(rtValue, container, nums, i + 1, n);
			container.pop_back();
			if (container.size())
				rtValue.push_back(container);
		}
	}
};