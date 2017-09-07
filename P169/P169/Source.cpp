#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		if (nums.empty())
			return 0;
	
		return helper(nums, 0, nums.size() - 1, nums.size()/2);
    }

	int helper(vector<int>& nums, int p, int r, int i)
	{
		if (p == r)
			return nums[p];

		int cursor = nums[0];
		vector<int>::iterator bound = std::partition(nums.begin()+p, nums.begin()+r+1, [=](int x)->bool{
			return cursor < x;
		});
		int q = std::distance(nums.begin(), bound);
		int k = q - p + 1;
		if (i == k)
			return *bound;
		else if(i < k)
			return helper(nums, p, q-1, i);
		else return helper(nums, q+1, r, i-k);
	}
};
