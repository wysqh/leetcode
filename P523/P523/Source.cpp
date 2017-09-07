#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
		unordered_set<int> modk;

		int sum = 0,  pre = 0;
		for (const auto& e: nums)
		{
			sum += e;
			int mod = k == 0 ? sum : sum % k;
			if (modk.find(mod) != modk.end())
				return true;
			modk.insert(pre);
			pre = mod;
		}

		return false;
    }
};