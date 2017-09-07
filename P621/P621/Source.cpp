#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> nums(26, 0);
		vector<int> lock(26, 0);
		for (const auto& c: tasks)
			nums[c-'A']++;

		int num = 0;
		while (!checkComplete(nums))
		{
			int dex = getIndex(nums, lock);
			
			
			for (auto& l: lock)
				if (l != 0)
					--l;
			num++;
			
			if (dex != -1)
			{
				nums[dex] --;
				lock[dex] = n;
			}
		}

		return num;
    }

	int getIndex(const vector<int>&nums, const vector<int>& lock)
	{
		vector<int> result(nums.size(), 0);
		std::copy(begin(nums), end(nums), begin(result));
		std::sort(begin(result), end(result), [](int x, int y)->bool{
			return x>y;
		});
		
		for (int i = 0; i < result.size(); i++)
			for (int j = 0; j < nums.size(); j++)
				if (nums[j] != 0 && nums[j] == result[i] && lock[j] == 0)
					return j;
		
		return -1;
	}

	bool checkComplete(vector<int>& nums)
	{
		for (const auto& e : nums)
			if (e != 0)
				return false;

		return true;
	}
};

int main()
{
	char a[] = {'A','A','A','A','A','A','B','C','D','E','F','G'};
	vector<char> test(begin(a), end(a));
	Solution s;
	cout << s.leastInterval(test, 2) << endl;
}