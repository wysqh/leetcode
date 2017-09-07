#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int start = 0;
		while (start + 2*k - 1 < s.size())
		{
			std::reverse(s.begin() + start, s.begin() + start + k);
			start += 2 * k;
		}

		if (start + k - 1 < s.size())
			std::reverse(s.begin() + start, s.begin() + start + k);
		else std::reverse(s.begin() + start, s.end());

		return s;
    }
};