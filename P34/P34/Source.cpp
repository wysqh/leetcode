#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	Total Accepted: 121341
	Total Submissions: 391787
	Difficulty: Medium
	Contributors: Admin
	Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

	Your algorithm's runtime complexity must be in the order of O(log n).

	If the target is not found in the array, return [-1, -1].

	For example,
	Given [5, 7, 7, 8, 8, 10] and target value 8,
	return [3, 4].
*/

//44.37%

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		int pos = -1;
		vector<int> rtValue;

		while (l <= r)
		{
			int m = (l + r) / 2;
			if (nums.at(m) > target)
				r = m - 1;
			else if (nums.at(m) < target)
				l = m + 1;
			else
			{
				pos = m;
				break;
			}
		}

		if (pos == -1 || nums.size() <= 1)
		{
			rtValue.push_back(-1);
			rtValue.push_back(-1);
			return rtValue;
		}

		int tmpL = pos, tmpR = pos;
		while (tmpL >= 0 && nums.at(tmpL) == target)
			tmpL = tmpL - 1;
		while (tmpR <= nums.size() - 1 && nums.at(tmpR) == target)
			tmpR = tmpR + 1;

		rtValue.push_back(tmpL + 1);
		rtValue.push_back(tmpR - 1);

		return rtValue;
    }
};

int main()
{
	Solution solution;
	int a[] = {2, 2};
	vector<int> test(begin(a), end(a));
	test = solution.searchRange(test, 2);
	for (auto e : test)
		cout << e << endl;
	return 0;
}