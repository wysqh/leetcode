#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
		if (nums.empty()) return 0;

		int result = 0;
		unordered_map<int, int> maps;

		for(const auto& n : nums)
			++maps[n];
		for(const auto& e: maps)
			if (maps.find(e.first+1) != maps.end())
				result = max(result, e.second + maps[e.first+1]);

		return result;
    }
};