#include <iostream>
#include <vector>

using namespace std;

//滑动窗口解法
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(26, 0), sv(26, 0), res;

		if (s.size() < p.size())
			return res;

		for (int i = 0; i < p.size(); i++)
		{
			++pv[p[i]-'a'];
			++sv[s[i]-'a'];
		}

		if (pv == sv)
			res.push_back(0);

		for (int i = 1; i <= s.size() - p.size(); i++)
		{
			int j = i + p.size() - 1;
			--sv[s[i-1]-'a'];

			++sv[s[j]-'a'];
			if (pv == sv)
				res.push_back(i);
		}

		return res;
    }
};