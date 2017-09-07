#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
		unordered_map<char, int> res;
		for (int i = 0; i < s.size(); i++)
		{
			++res[s[i]];
			if (s[i] == 'A' && res[s[i]] > 1)
				return false;
			if (s[i] == 'L' && i > 0)
			{
				if (s[i-1] != 'L')
					res[s[i]] = 1;
				else if (res[s[i]] >= 3)
					return false;
				else;
			}
		}

		return true;
	}
};