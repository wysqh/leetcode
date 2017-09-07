#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		if (nums.empty() || r*c != nums.size() * nums[0].size())
			return nums;

		vector<int> oned;
		vector<vector<int>> ans(r, vector<int>(c, 0));
		for (const auto&num : nums)
			for (const auto& e: num)
				oned.push_back(e);

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				ans[i][j] = oned[i*c+j];

		return ans;
    }
};