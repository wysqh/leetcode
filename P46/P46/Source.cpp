#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//10.91%

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> rtValue;
		vector<int> container;
		sort(begin(nums), end(nums));
		
		findAnswer(rtValue, nums, container, 0);

		return rtValue;
    }

	void findAnswer(vector<vector<int>>& rtValue, vector<int> nums, vector<int> container, int index)
	{
		if (index == nums.size())
		{
			rtValue.push_back(container);
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (find(begin(container), end(container), nums.at(i)) != end(container))
				continue;

			container.push_back(nums.at(i));
			findAnswer(rtValue, nums, container, index + 1);
			container.pop_back();
		}
	}
};

int main()
{

	return 0;
}