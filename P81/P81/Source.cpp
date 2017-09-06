#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//3.19%

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));

		int l = 0, r = nums.size() - 1;
		bool bFind = false;

		while (l <= r)
		{
			int m = (l+r)/2;
			if (nums.at(m) < target)	l = m + 1;
			else if (nums.at(m) > target)	r = m - 1;
			else 
			{
				bFind = true;
				break;
			}
		}

		return bFind;
    }
};