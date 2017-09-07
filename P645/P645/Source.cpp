#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
		unordered_map<int, int> res;
		vector<int> vals;
		for (int i = 1; i <= nums.size(); ++i)
			res[i] = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			++res[nums[i]];
			if (res[nums[i]] == 2)
				vals.push_back(nums[i]);
		}

		for (const auto& e: res)
			if (e.second == 0)
			{
				vals.push_back(e.first);
				break;
			}

		return vals;
    }
};

int main()
{
	int a[] = {2,3,3,4};
	vector<int> nums(begin(a), end(a));
	Solution s;
	s.findErrorNums(nums);
}