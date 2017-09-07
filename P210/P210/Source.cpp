#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
#define Undefined INT_MIN
		vector<vector<int>> res(numCourses, vector<int>(numCourses, Undefined));
		vector<int> indegree(numCourses, 0);

		for (const auto& p : prerequisites)
		{
			res[p.first][p.second] = 1;
			++indegree[p.second];
		}

		vector<int> order(numCourses);
		vector<int>::iterator it;
		int index = 0;
		while ((it = find(begin(indegree), end(indegree), 0)) != end(indegree))
		{
			int dis = std::distance(indegree.begin(), it);
			for (int j = 0; j < numCourses; j++)
				if (j!=dis&&res[dis][j] != Undefined)
					--indegree[j];

			order[index++] = dis;
			*it = Undefined;
		}

		if (index != indegree.size())
			return vector<int>();

		std::reverse(begin(order), end(order));
		return order;
    }
};