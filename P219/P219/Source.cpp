#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			if (m.find(nums[i]) == m.end())
				m[nums[i]] = i;
			else
			{
				auto it = m.find(nums[i]);
				int dex = it->second;
				if (i - dex <= k)
					return true;
				else m[nums[i]] = i;
			}
		}

		return false;
    }
};