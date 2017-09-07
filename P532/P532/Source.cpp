#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
		if (k < 0) return 0;
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
			++m[nums[i]];
		int res = 0;
		if (k != 0)
		{
			for (auto it = m.begin(); it != m.end(); ++it)
				if (m.find(it->first + k) != m.end())
					++res;
		}
		else
		{
			for (auto it = m.begin(); it != m.end(); ++it)
				if (it->second > 1)
					++res;
		}
		return res;
    }
};
