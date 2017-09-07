#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int hours[4] = {1,2,4,8};
	int minutes[6] = {1,2,4,8,16,32};
    
	vector<string> readBinaryWatch(int num) {
		vector<string> res;
		for (int i = 0; i <= num; ++i)
			backtrace(i, num - i, res);

		return res;
    }

	void backtrace(int hc, int mc, vector<string>& res)
	{
		traceHours(hc, 0, 0, mc, res, 0);
	}

	void traceHours(int hc, int index, int num, int mc, vector<string>& res, int nxt)
	{
		if (index == hc)
		{
			if (hc == 0)  
			{
				traceMinutes(mc, 0, 0, "0:", res, 0);
				return;
			}
			if (num > 11) return;
			
			traceMinutes(mc, 0, 0, to_string(num)+":", res, 0);
			return;
		}

		for (int i = nxt; i < 4; i++)
			traceHours(hc, index+1, num+hours[i], mc, res, i+1);
	}

	void traceMinutes(int mc, int index, int num, string str, vector<string>& res, int nxt)
	{
		if (index == mc)
		{
			if (num >= 60)
				return;
			if (mc == 0)
			{
				res.push_back(str+"00");
				return;
			}
			if (num < 10)
			{
				res.push_back(str+"0"+to_string(num));
				return;
			}
			res.push_back(str+to_string(num));
			return;
		}

		for (int i = nxt; i < 6; i++)
			traceMinutes(mc, index+1, num+minutes[i], str, res, i+1);
	}
};


