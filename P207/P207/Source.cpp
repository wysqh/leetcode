#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	map<int, multiset<int>> targets;
	vector<int> indegree;
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (prerequisites.empty())
			return true;

		indegree.assign(numCourses, 0);
		for (const auto&pre : prerequisites)
			targets[pre.first].insert(pre.second);
		for (const auto&t : targets)
			for (const auto&e : t.second)
				++indegree[e];

		vector<int>::iterator it;
		while ((it = std::find(begin(indegree), end(indegree), 0)) != end(indegree))
		{
			int dis = std::distance(indegree.begin(), it);
			for (const auto& e: targets[dis])
				--indegree[e];

			*it = INT_MIN;
		}

		return (std::find_if(begin(indegree), end(indegree), [&](const int& e)->bool{
			return e > 0;
		}) == end(indegree));
    }
};