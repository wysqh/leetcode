#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
		if (s.empty())
			return s;

		stack<string> sym;
		string decodes = "", tmp = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '[')
			{
				sym.push(tmp);
				tmp = "";
			}
			else if (s[i] == ']')
			{
				sym.push(tmp);
				tmp = "";

				string alpha = sym.top();
				sym.pop();
				string nonesen = sym.top();
				int count = 0, base = 1;
				for (int i = nonesen.size() - 1; i >= 0; --i)
				{
					if (nonesen[i] >= '9' || nonesen[i] <= '0')
						break;
					count += (nonesen[i] - '0') * base;
					base *= 10;
				}
				
				string outer = "";
				for (int i = 0; i < count; i++)
					outer += alpha;
				
				string decode = nonesen.substr(0, nonesen.size()-1) + outer;
				sym.pop();
				tmp = decode;
			}
			else tmp += s[i];
		}

		return tmp;
	}
};