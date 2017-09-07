#include <iostream>
<<<<<<< HEAD
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
		unordered_map<int, int> cur;
		for (const auto& e: nums)
			if(cur.find(e) == cur.end())
				cur.insert(pair<int, int>(e, e));

		vector<int> ans;
		for (int i = 1; i <= nums.size(); i++)
			if (cur.count(i) == 0 )
				ans.push_back(i);

		return ans;
    }
};
=======
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
using namespace std;


//"hit" -> "hot" -> "dot" -> "dog" -> "cog",

struct Graph
{
public:
	int val;
	vector<Graph*> nodes;
	bool bFog;
	bool bReach;

	Graph(int _val, bool _bFog) : val(_val), bFog(_bFog), bReach(false) {}
};

#define INT_MAX 2147483647
#define UnReachable INT_MAX
class Solution {
public:
    int calculateMin(int dstpos, int foggyCity, vector<vector<int>>& weights, vector<int>& container)
	{
		vector<Graph*> gVec;
		for (int i = 1; i < 7; ++i)
		{
			Graph* node = nullptr;
			if (foggyCity == i)
				node = new Graph(i, true);
			else node = new Graph(i, false);

			gVec.push_back(node);
		}

		for (int i = 0; i < weights.size(); ++i)
			for (int j = 0; j < weights[0].size(); ++j)
				if (weights[i][j] != UnReachable && weights[i][j] != 0)
					gVec.at(i)->nodes.push_back(gVec[j]);

		int min = INT_MAX;
		vector<int> tmp;
		
		findMinPath(dstpos, gVec[4], weights, 0, min, tmp, container);

		return min == INT_MAX ? 1000 : min;
    }

	void findMinPath(int dstpos, Graph* current,  vector<vector<int>>& weights, int length, int& min, vector<int>& container, vector<int>& rtValue)
	{
		if (dstpos == current->val)
		{
			rtValue = container;
			min = (min < length ? min : length);
			return;
		}

		for (auto& g: current->nodes)
		{
			if (g->bFog || g->bReach)
				continue;

			g->bReach = true;
			container.push_back(g->val);
			findMinPath(dstpos, g, weights, length + weights[current->val-1][g->val-1], min, container, rtValue);
			container.pop_back();
			g->bReach = false;
		}
	}
};

int main()
{
	Solution s;
	vector<vector<int>> weights(6);
	int a[][6] = {
		 {0,2,10,5,3,UnReachable},
		 {UnReachable,0,12,UnReachable,UnReachable,10},
		 {UnReachable,UnReachable,0,UnReachable,7,UnReachable},
		 {2,UnReachable,UnReachable,0,2,UnReachable},
		 {4,UnReachable,UnReachable,1,0,UnReachable},
		 {3, UnReachable, 1, UnReachable, 2, 0},
	};

	for (int i = 0; i < weights.size(); ++i)
		weights[i].assign(begin(a[i]), end(a[i]));

	int dst = 0;
	int foggy = 0;
	cin >> dst;
	cin >> foggy;
	
	vector<int> rtValue;

	int answer;
	answer =  s.calculateMin(dst, foggy, weights, rtValue);
	cout << answer << endl;
	if (answer == 0)
		cout << "[5]" << endl;
	if (answer == 1000)
		cout << "[]" << endl;
	else
	{
		cout << "[5,";
		for (int i = 0; i < rtValue.size(); ++i)
		{
			if (i == rtValue.size() - 1)
				cout << " " << rtValue[i] << "]" << endl;
			else cout << " " << rtValue[i] << ",";
		}
	}
}
>>>>>>> 2d86cdadada16552b9cf35a989a021746884a9c4
