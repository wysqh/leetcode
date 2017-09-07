#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int minN = INT_MAX;
		vector<string> rtValue;
		unordered_map<string, int> maps;

		for (int i = 0; i < list1.size(); i++)
			maps.insert(make_pair(list1[i], i));

		for (int i = 0; i  < list2.size(); i++)
		{
			auto it = maps.find(list2[i]);
			if ( it != maps.end())
				minN = min(minN, it->second + i);
		}

		for (int i = 0; i  < list2.size(); i++)
		{
			auto it = maps.find(list2[i]);
			if ( it != maps.end() && minN == it->second + i)
				rtValue.push_back(list2[i]);
		}

		return rtValue;
    }
};