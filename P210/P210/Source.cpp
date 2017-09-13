#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
 A Quicker Version
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, vector<int>> sides;
        unordered_map<int, list<int>> degrees;
        unordered_map<int, list<int>::iterator> iters;
        
        vector<int> indegrees = vector<int>(numCourses + 1, 0);
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            sides[prerequisites[i].second].push_back(prerequisites[i].first);
            indegrees[prerequisites[i].first]++;
        }
        
        for(int i = 0; i < numCourses; i++)
        {
            degrees[indegrees[i]].push_back(i);
            iters[i] = (--degrees[indegrees[i]].end());
        }
        
        vector<int> answer;
        
        while(!degrees[0].empty())
        {
            int k = degrees[0].back();
            degrees[0].pop_back();
            answer.push_back(k);
            
            for(int i = 0; i < sides[k].size(); i++)
            {
                int lastin = indegrees[sides[k][i]];
                indegrees[sides[k][i]]--;
                
                degrees[lastin].erase(iters[sides[k][i]]);
                degrees[lastin - 1].push_back(sides[k][i]);
                iters[sides[k][i]] = (--degrees[lastin - 1].end());
            }
        }
        
        if(answer.size() < numCourses)
        {
            answer.clear();
        }
        
        return answer;
    }
};

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