#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int base = 0, exp = 1;
		std::reverse(s.begin(), s.end());

		for (const auto& ch : s)
		{
			int num = ch - 'A' + 1;
			base += num * exp;
			exp *= 26;
		}
		

		return base;
    }
};