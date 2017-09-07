#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
		int sc = 0, tc = 0;
		while (sc < s.size() && tc < t.size())
		{
			if (s[sc] == t[tc])
				++sc, ++tc;
			else ++tc;
		}

		return sc == s.size();
    }
};