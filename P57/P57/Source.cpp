#include <vector>
#include <iostream>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

//27.48%

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> rtValue;
		vector<Interval>::iterator it;
		for (it = intervals.begin(); it != intervals.end(); it++)
		{
			if (newInterval.start < (*it).start)
			{
				if (newInterval.end < (*it).start)
				{
					rtValue.push_back(newInterval);
					rtValue.push_back(*it);
					break;
				}
				else if ( newInterval.end >= (*it).start && newInterval.end <= (*it).end)
				{
					rtValue.push_back(Interval(newInterval.start, (*it).end));
					break;
				}
				else
				{
					continue;
				}
			}
			else if (newInterval.start >= (*it).start && newInterval.start <= (*it).end)
			{
				if (newInterval.end <= (*it).end)
				{
					rtValue.push_back(*it);
					break;
				}
				else
				{
					newInterval.start = (*it).start;
					continue;
				}
			}
			else
			{
				rtValue.push_back(*it);
				continue;
			}
		}

		if (it == intervals.end())
		{
			rtValue.push_back(newInterval);
			return rtValue;
		}

		while ((++it) != intervals.end())
		{
			rtValue.push_back(*it);
		}
		
		return rtValue;
    }
};

int main()
{
	vector<Interval> test;
	test.push_back(Interval(1,2));
	test.push_back(Interval(3,5));
	test.push_back(Interval(6,7));
	test.push_back(Interval(8,10));
	test.push_back(Interval(12,16));
	Interval i(3,9);
	Solution s;
	test =s.insert(test, i);
	for (auto e : test)
		cout << e.start << " " << e.end << endl;
	return 0;	
}