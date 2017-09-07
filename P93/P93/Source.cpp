#include <iostream>
#include <vector>
#include <string>
using namespace std;

//16.32%

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> rtValue;
		generate(rtValue, s, "");
		
		for (auto &e: rtValue)
			e.erase(e.end - 1);

		return rtValue;
    }

	void generate(vector<string> &rtValue, string s, string val)
	{
		if (countDigits(val) == 4)
		{
			if (s.empty())
				rtValue.push_back(val);
			return;
		}
		if (s.size() >= 1)
			generate(rtValue, s.substr(1),  val + s.substr(0, 1) + "." );
		if (s.size() >= 2)
		{
			if ((s.substr(0, 2)).at(0) == '0')
				return;

			generate(rtValue, s.substr(2), val + s.substr(0, 2) + "." );
		}
		if (s.size() >= 3)
		{
			string c = s.substr(0, 3);
			if (c.at(0) == '0')
				return;
			if (atoi(c.c_str()) < 100 || atoi(c.c_str()) > 255)
				return;
			
			generate(rtValue, s.substr(3), val + s.substr(0, 3) + ".");
		}

		return;
	}

	int countDigits(string s)
	{
		int cnt = 0;
		for (auto e : s)
			if (e == '.')
				++cnt;

		return cnt;
	}
};

int main()
{
	vector<string> test;
	Solution s;

	test = s.restoreIpAddresses("0255113");
	for (auto e: test)
		cout << e << " ";
	cout << endl;

	string ss = "123";
	cout << ss.substr(3) << endl;
	return 0;
}