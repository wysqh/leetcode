#include <iostream>
#include <vector>
#include <algorithm>>
#include <set>
#include <map>
#include <cctype>
#include <string>
using namespace std;

class Solution
{
	map<string, multiset<string>> targets;
	vector<string> routes;
	vector<string> findItinerary(vector<pair<string, string>> tickets) 
	{
		for (const auto& ticket: tickets)
			targets[ticket.first].insert(ticket.second);

		helper("JFK");
		return vector<string>(routes.rbegin(),routes.rend());
	}

	void helper(string airport)
	{
		while (targets[airport].size())
		{
			string next = *targets[airport].begin();
			targets[airport].erase(targets[airport].begin());
			helper(next);
		}

		routes.push_back(airport);
	}
};

class Solution
{
public:
	map<string, multiset<string>> targets;
	vector<string> route;
	
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		for (auto ticket : tickets)
			targets[ticket.first].insert(ticket.second);
		visit("JFK");
		return vector<string>(route.rbegin(), route.rend());
	}

	void visit(string airport) {
		while (targets[airport].size()) {
			string next = *targets[airport].begin();
			targets[airport].erase(targets[airport].begin());
			visit(next);
		}
		route.push_back(airport);
	}
};

//class Solution {
//public:
//	multimap<pair<string, string>, bool> used;
//    vector<string> findItinerary(vector<pair<string, string>> tickets) {
//		vector<string> res;
//		vector<vector<string>> rtvals;
//
//		if (tickets.empty())
//			return res;
//		for (const auto&e: tickets)
//			used.insert(make_pair(e, false));
//
//		helper(rtvals, tickets, res, make_pair("0", "JFK"), 0);
//		if (rtvals.size() == 1)
//			return rtvals[0];
//		for (const auto& e: rtvals)
//		{
//			for (const auto& c: e)
//				cout << c << " ";
//			cout << endl;
//		}
//		std::sort(begin(rtvals), end(rtvals), [&](const vector<string>&a, const vector<string>& b)->bool{
//			for (int i = 0; i < a.size(); ++i)
//				if (a[i] != b[i])
//					return std::lexicographical_compare(begin(a[i]), end(a[i]),
//					begin(b[i]), end(b[i]));
//		});
//		return rtvals[0];
//    }
//
//	void helper(vector<vector<string>>& rtvals, vector<pair<string, string>>& tickets, vector<string>& rtVals,
//		pair<string, string> cur, int index)
//	{
//		if (index == tickets.size())
//		{
//			rtVals.push_back(cur.second);
//			rtvals.push_back(rtVals);
//			rtVals.pop_back();
//			return;
//		}
//
//		for (int i = 0; i < tickets.size(); ++i)
//		{
//			pair<multimap<pair<string, string>, bool>::iterator, multimap<pair<string, string>, bool>::iterator> ret = used.equal_range(tickets[i]);
//			for (multimap<pair<string, string>, bool>::iterator it = ret.first; it != ret.second; ++it)
//				if (!(*it).second)
//					if (tickets[i].first == cur.second)
//					{
//						it->second = true;
//						rtVals.push_back(tickets[i].first);
//						helper(rtvals, tickets, rtVals, tickets[i], index+1);
//						it->second = false;
//						rtVals.pop_back();
//					}
//		}
//	}
//};


int main()
{
	/*Solution s;
	vector<pair<string, string>> ti;
	ti.push_back(make_pair("JFK", "ANU"));
	ti.push_back(make_pair("ANU", "EZE"));
	ti.push_back(make_pair("EZE", "AXA"));
	ti.push_back(make_pair("AXA", "TIA"));
	ti.push_back(make_pair("TIA", "ANU"));
	ti.push_back(make_pair("ANU", "JFK"));
	ti.push_back(make_pair("JFK", "TIA"));
	ti.push_back(make_pair("TIA", "ANU"));
	ti.push_back(make_pair("ANU", "TIA"));
	ti.push_back(make_pair("TIA", "JFK"));
	
	
	s.findItinerary(ti);*/
	vector<int> vec;
	vec.push_back(1);
	std::sort(begin(vec), end(vec), [&](const int&a, const int& b)->bool{
		return a < b;
	});
}

//int main ()
//{
//  std::multimap<char,int> mymm;
//
//  mymm.insert(std::make_pair('x',50));
//  mymm.insert(std::make_pair('x',50));
//  mymm.insert(std::make_pair('y',150));
//  mymm.insert(std::make_pair('y',200));
//  mymm.insert(std::make_pair('z',250));
//  mymm.insert(std::make_pair('z',300));
//
//  for (char c='x'; c<='z'; c++)
//  {
//	  auto s = mymm.equal_range(c);
//    std::cout << "There are " << mymm.count(c) << " elements with key " << c << ":";
//    std::multimap<char,int>::iterator it;
//    for (it=mymm.equal_range(c).first; it!=mymm.equal_range(c).second; ++it)
//      std::cout << ' ' << (*it).second;
//    std::cout << '\n';
//  }
//
//  return 0;
//}