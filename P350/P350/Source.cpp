#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
		unordered_map<int, int> maps;
		unordered_map<int, int> tmp;
		for (const auto& e: nums1)
			++maps[e];
		for (const auto& e: nums2)
			++tmp[e];
			
		
		
		for (auto it: maps)
		{
			int minN = min(it.second, tmp[it.first]);
			for (int i = 0; i < minN; i++)
				res.push_back(it.first);
		}

		return res;
    }
};