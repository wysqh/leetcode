#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
	Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
	Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int min = INT_MAX;
		int rtValue = 0;
		sort(begin(nums), end(nums));
		
		for (int i = 0; i < nums.size() - 2; i++)
		{
			int result = target - nums.at(i);
			int head = i + 1, tail = nums.size() - 1;
			while (head < tail)
			{
				if ( min > abs(result - (nums.at(head) + nums.at(tail))) )
				{
					rtValue = nums.at(head) + nums.at(tail) + nums.at(i);
					min = abs(result - nums.at(head) - nums.at(tail));
				}
				
				if (result - (nums.at(head) + nums.at(tail)) < 0)	--tail;
				else if (result - (nums.at(head) + nums.at(tail)) > 0) ++head;
				else return target;
			}
		}

		return rtValue;
    }
};

int main()
{
	Solution solution;
	int a[] = {1,2,4,8,16,32,64,128};
	vector<int> test(begin(a), end(a));
	cout << solution.threeSumClosest(test, 82) << endl;

	return 0;
}