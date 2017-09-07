#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmpFunc(int a, int b)
{
	return (a > b);
}

//79.60%

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		reverse(begin(nums), end(nums));
		vector<int>::iterator it;
		for (it = nums.begin(); it != nums.end(); it++)
			if ((it+1) != nums.end() && *it > *(it+1))
			{
				vector<int>::iterator tmpIt = nums.begin();
				while (tmpIt != it && *tmpIt <= *(it+1))
					tmpIt++;

				if (tmpIt == it)
				{
					int tmp = *it;
					*it = *(it+1);
					*(it+1) = tmp;
				}
				else
				{
					int ttmp = *tmpIt;
					*tmpIt = *(it+1);
					*(it+1) = ttmp;
				}

				break;
			}

		if (it == nums.end())
			return;

		sort(nums.begin(), it+1, cmpFunc);
		reverse(nums.begin(), nums.end());
    }
};

int main()
{
	Solution solution;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(1);
	solution.nextPermutation(nums);
	return 0;
}