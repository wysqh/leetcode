#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
		unordered_map<int, int> hter;
		vector<int> dis(houses.size(), INT_MAX);
		for (const auto& e : heaters)
			hter[e] = e;

		for (int i = 0; i < houses.size(); ++i)
		{
			if (hter.find(houses[i])!=hter.end())
			{
				dis[i] = 0;
				continue;
			}
			for (int j = 0; j < heaters.size(); ++j)
			{
				dis[i] = min(dis[i], abs(heaters[j]-houses[i]));
			}
		}

		return *max_element(dis.begin(), dis.end());
    }
};