#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sv(26, 0), tv(26, 0);
		if (s.size() != t.size())
			return false;

		for (int i = 0; i < s.size(); ++i)
		{
			++sv[s[i]-'a'];
			++tv[t[i]-'a'];
		}

		return sv == tv;
    }
};