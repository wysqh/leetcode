#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		std::sort(begin(nums), end(nums));
		auto bound = std::unique(begin(nums), end(nums));

		return std::distance(nums.begin(), bound) != nums.size();
    }
};