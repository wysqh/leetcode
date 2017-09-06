#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//72.72%  BFS

class Solution {
public:
	//BFS
    int jump(vector<int>& nums) {
		int cpos = 0, npos = 0;
		int steps = 0, i = 0;

		while (cpos < nums.size() - 1)
		{
			npos = (npos > nums[i] + i) ? npos : nums[i] + i;
			if (i == cpos)
			{
				steps ++;
				cpos = npos;
			}
			i++;
		}

		return steps;
    }


	//DFS
	void findAnswer(vector<int>& nums, int index, int length, int& min)
	{
		if (index == nums.size() - 1)
		{
			min = (length < min) ? length : min;
			return;
		}
		if (length >= min)
			return;

		for (int i = nums.at(index); i >= 1; --i)
		{
			if (i + index > nums.size() - 1)
				continue;

			findAnswer(nums, index + i, length + 1, min);
		}

	}
};

int main()
{
	int a[] = {1,2};
	Solution s;
	cout << s.jump(vector<int>(begin(a), end(a))) << endl;
	return 0;
}