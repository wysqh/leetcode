#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


/*
	Not good answer.
	Using O(n) Space & O(N) Time.
*/
class Solution {
public:
	unordered_map<int, int> targets;
    vector<int> majorityElement(vector<int>& nums) {
        for (const auto&e: nums)
			++targets[e];
		vector<int> res;
		int size = nums.size() / 3;
		for (const auto&tar : targets)
			if (tar.second > size)
				res.push_back(tar.first);

		return res;
	}
};