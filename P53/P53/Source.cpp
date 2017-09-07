#include <iostream>
#include <vector>

using namespace std;

//7.79%

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		return find_maximun_subarray(nums, 0, nums.size() - 1);
    }

	int find_max_crossing_subarray(vector<int> &nums, int l, int m, int h)
	{
		int leftSum = -INT_MAX, rightSum = -INT_MAX;
		int sum = 0;
		for (int i = m + 1; i <= h; i++)
		{
			sum += nums.at(i);
			if (sum > leftSum)
				leftSum = sum;
		}

		sum = 0;
		for (int i = m; i >= l; i--)
		{
			sum += nums.at(i);
			if (sum > rightSum)
				rightSum = sum;
		}

		return rightSum + leftSum;
	}

	int find_maximun_subarray(vector<int> &nums, int l, int h)
	{
		if ( l == h)
			return nums.at(l);
		
		int mid = (l+h)/2;
		int maxleft = find_maximun_subarray(nums, l, mid);
		int maxright = find_maximun_subarray(nums, mid+1, h);
		int maxcrossing = find_max_crossing_subarray(nums, l, mid, h);
		
		if (maxleft >= maxright && maxleft >= maxcrossing)
			return maxleft;
		else if (maxright >= maxleft && maxright >= maxcrossing)
			return maxright;
		else return maxcrossing;
	}

};