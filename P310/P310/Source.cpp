#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>
using namespace std;

class Solution {
public:
	unordered_map<int, set<int>> graph;
	vector<int> indegree;
	vector<bool> walked;
	deque<int> queue;
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		int size = edges.size() + 1;
		indegree.assign(size, 0);
		walked.assign(size, false);
		if (edges.empty())
			return vector<int>(1, 0);

		for (const auto&edge :edges)
		{
			graph[edge.first].insert(edge.second);
			graph[edge.second].insert(edge.first);
		}

		for (const auto&edge: edges)
		{
			++indegree[edge.first];
			++indegree[edge.second];
		}

		for (int i = 0; i < indegree.size(); ++i)
		{
			if (indegree[i] == 1)
			{
				queue.push_back(i);
				walked[i] = true;
			}
		}

		while (size>2)
		{
			int cursize = queue.size();
			for (int i = 0; i < cursize; ++i)
			{
				int j = queue.front();
				queue.pop_front();
				for (const auto&g: graph[j])
				{
					--indegree[g];
					if (!walked[g] && indegree[g] == 1)
					{
						queue.push_back(g);
						walked[g] = true;
					}
				}
			}
			size -= cursize;
		}

		vector<int> ans(queue.begin(), queue.end());
		return ans;
    }
};