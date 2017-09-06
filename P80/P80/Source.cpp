#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

//16.43%

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		unordered_map<int, int> dup2nums;
		for (auto e: nums)
			if (dup2nums[e] <= 2)
				dup2nums[e]++;

		int length = 0;
		nums.clear();
		for (auto e: dup2nums)
			for (int i = 0; i < e.second; i++)
				nums.push_back(e.first);


		for (auto e: dup2nums)
			length += e.second;

		return length;
    }
};