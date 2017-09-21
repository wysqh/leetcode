#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		std::sort(people.begin(), people.end(), [](const pair<int, int>&a, 
			const pair<int, int>& b)
		{
			return (a.first > b.first) || (a.first == b.first && a.second < b.second);
		});

		list<pair<int, int>> lres;
		for (const auto&p : people)
		{
			auto it = lres.begin();
			for (int i = 0; i < p.second; i++)
				it++;
			lres.insert(it, p);
		}
		return vector<pair<int, int>>(begin(lres), end(lres));
    }
};