#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
		if (nums.empty())
			return res;

		res.push_back(to_string(nums[0]));
		string tmp;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] - nums[i-1] == 1)
				tmp = "->" + to_string(nums[i]);
			else
			{
				res.back() += tmp;
				tmp.clear();
				res.push_back(to_string(nums[i]));
			}
		}
		res.back() += tmp;
		return res;
    }
};