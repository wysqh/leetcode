#include <vector>
#include <algorithm>

using namespace std;

//6.29%

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool compare(Interval a, Interval b)
{
	return (a.start < b.start);
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		if (!intervals.size())
			return intervals;

		sort(begin(intervals), end(intervals), compare);
		vector<Interval>::iterator prior = intervals.begin();
		for (vector<Interval>::iterator it = intervals.begin() + 1; it != intervals.end(); )
		{
			if( (*it).start <= (*prior).end)
			{
				if((*it).end > (*prior).end)
					(*prior).end = (*it).end;

				it = intervals.erase(it);
			}
			else it++;
		}

		return intervals;
    }
};