#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
		unordered_map<int, int> maps;
		for(const auto& e: nums1)
			maps[e] = e;

		for (const auto& e: nums2)
			if (maps.find(e) != maps.end())
				res.insert(e);

		return vector<int>(begin(res), end(res));
    }
};