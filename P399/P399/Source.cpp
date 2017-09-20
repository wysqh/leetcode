#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	unordered_map<string, unordered_map<string, double>> graph;
	unordered_map<string, bool> walked;
	vector<double> res;

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		
		for (int i = 0; i < equations.size(); ++i)
		{
			graph[equations[i].first][equations[i].second] = values[i];
			if (values[i] != 0)
				graph[equations[i].second][equations[i].first] = 1 / values[i];
			walked[equations[i].first] = false;
			walked[equations[i].second] = false;
		}

		
		for (int i = 0; i < queries.size(); i++)
		{
			for (auto&w : walked)
				w.second = false;

			string src = queries[i].first;
			string dst = queries[i].second;
			if (walked.find(src) == walked.end() || walked.find(dst) == walked.end())
				res.push_back((double)-1);
			else
			{
				double val = dfs(src, dst);
				res.push_back(val < 0 ? -1 : val);
			}
		}

		return res;
    }

	double dfs(string src, const string& dst)
	{
		if (graph[src].find(dst) != graph[src].end())
			return graph[src][dst];

		double val = -1;
		walked[src] = true;
		for (const auto& g: graph[src])
		{
			if (!walked[g.first])
				val = g.second * dfs(g.first, dst);
		}

		return val;
	}
};

int main()
{
	Solution s;
	vector<pair<string, string>> eq;
	eq.push_back(make_pair("a","b"));
	eq.push_back(make_pair("b","c"));
	vector<double> vals;
	vals.push_back(2);
	vals.push_back(3);
	vector<pair<string, string>> qu;
	qu.push_back(make_pair("a","c"));
	qu.push_back(make_pair("b","c"));
	qu.push_back(make_pair("a","e"));
	qu.push_back(make_pair("a","a"));
	qu.push_back(make_pair("x","x"));
	vector<double> ds;
	ds = s.calcEquation(eq, vals, qu);
	for (const auto& d :ds)
		cout << d << " ";
}