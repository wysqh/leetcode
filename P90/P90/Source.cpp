#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


//18.47%

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> rtValue;
		if (nums.size() != 0)
		{
    		sort(begin(nums), end(nums));
    		generate(rtValue, nums);
		}
		return vector<vector<int>>(begin(rtValue), end(rtValue));
    }

	void generate(set<vector<int>> &rtValue, vector<int> nums)
	{
		if (nums.size() == 1)
		{
			rtValue.insert(vector<int>(nums));
			rtValue.insert(vector<int>());
			return;
		}

		vector<int> sub(begin(nums), end(nums)-1);
		generate(rtValue, sub);

		int size = rtValue.size();
		vector<vector<int>> cpy;
		for (auto vec: rtValue)
			cpy.push_back(vec);
		
		for (int i = 0; i < size; ++i)
		{
			cpy[i].push_back(nums.at(nums.size() - 1));
			rtValue.insert(cpy[i]);
		}
	}
};